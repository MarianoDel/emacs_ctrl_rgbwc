//-----------------------------------------------------------------
// #### COLOR CONTROL BOARD RGBWC PROJECT  F030 - Custom Board ####
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ## @CPU:    STM32F030
// ##
// #### MAIN.C ####################################################
//-----------------------------------------------------------------

// Includes --------------------------------------------------------------------
#include "stm32f0xx.h"

#include "gpio.h"
#include "uart.h"
#include "hard.h"
#include "comm.h"
#include "test_functions.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Externals -------------------------------------------------------------------
// -- Externals from or for Serial Port --------------------
volatile unsigned char usart1_have_data = 0;

// -- Externals for the timers -----------------------------
volatile unsigned short wait_ms_var = 0;


// Globals ---------------------------------------------------------------------
typedef enum {
    CHECKING_SWITCHES = 0,
    SEND_DATA,
    SENDED_DATA_WAIT_ACK,
    WAIT_FREE_SWITCHES
    
} main_state_e;

volatile unsigned short timer_standby = 0;


// Module Private Functions ----------------------------------------------------
void SysTickError (void);


//-------------------------------------------//
// @brief  Main program.
// @param  None
// @retval None
//------------------------------------------//
int main(void)
{
    main_state_e main_state = CHECKING_SWITCHES;
    char color_send [20] = { 0 };
    unsigned char sended_cntr = 0;

    // Gpio Configuration.
    GPIO_Config();

    // Systick Timer Activation
    if (SysTick_Config(48000))
        SysTickError();

    // Test Functions
    // TF_Usart1_Gpio_Input();
    // TF_Usart1_Multiple();
    // TF_Usart1_TxRx();

    // Peripherals Activation
    Usart1Config();
    
    
    while (1)
    {
        switch (main_state)
        {
        case CHECKING_SWITCHES:
            if (S_RED)
            {
                strcpy(color_send, "red\n");
                sended_cntr = 5;
                main_state = SEND_DATA;
            }
            
            if (S_GREEN)
            {
                strcpy(color_send, "green\n");
                sended_cntr = 5;
                main_state = SEND_DATA;
            }
            
            if (S_BLUE)
            {
                strcpy(color_send, "blue\n");
                sended_cntr = 5;
                main_state = SEND_DATA;
            }
            
            if (S_WARM)
            {
                strcpy(color_send, "warm\n");
                sended_cntr = 5;
                main_state = SEND_DATA;
            }
            
            if (S_COLD)
            {
                strcpy(color_send, "cold\n");
                sended_cntr = 5;
                main_state = SEND_DATA;
            }

            break;

        case SEND_DATA:
            if (sended_cntr)
            {
                sended_cntr--;
                timer_standby = 50;
                CommFlushAck();    //flush ok and nok
                Usart1Send(color_send);
                main_state = SENDED_DATA_WAIT_ACK;
            }
            else
                main_state = CHECKING_SWITCHES;
            
            break;

        case SENDED_DATA_WAIT_ACK:
            if (CommCheckOK())
            {
                //sended ok!
                main_state = WAIT_FREE_SWITCHES;
                timer_standby = 2000;
            }

            if ((CommCheckNOK()) || (!timer_standby))
            {
                //error in comms or timed out
                main_state = SEND_DATA;
            }
            
            break;

        case WAIT_FREE_SWITCHES:
            if (!timer_standby)
                main_state = CHECKING_SWITCHES;

            if (!(S_RED) &&
                !(S_GREEN) &&
                !(S_BLUE) &&
                !(S_WARM) &&
                !(S_COLD) &&
                (timer_standby < 1800))
                main_state = CHECKING_SWITCHES;
            
            break;
            
        default:
            break;
        }

        // Continuous checks
        UpdateCommunications();
    }
    
    return 0;
}

//--- End of Main ---//


void TimingDelay_Decrement(void)
{
    if (wait_ms_var)
        wait_ms_var--;

    if (timer_standby)
        timer_standby--;

}


void SysTickError (void)
{
    //Capture systick error...
    while (1)
    {
        // if (LED)
        //     LED_OFF;
        // else
        //     LED_ON;

        for (unsigned char i = 0; i < 255; i++)
        {
            asm ("nop \n\t"
                 "nop \n\t"
                 "nop \n\t" );
        }
    }
}

//--- end of file ---//
