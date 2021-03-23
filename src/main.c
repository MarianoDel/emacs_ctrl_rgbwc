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
    SEND_DATA_WAIT_ACK
    
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

    // Gpio Configuration.
    GPIO_Config();

    // Systick Timer Activation
    if (SysTick_Config(48000))
        SysTickError();

    // Test Functions
    TF_Usart1_Gpio_Input();
    // TF_Usart1_Multiple();
    // TF_Usart1_TxRx();

    // Peripherals Activation
    Usart1Config();

    
    
    while (1)
    {
        switch (main_state)
        {
        case CHECKING_SWITCHES:
            break;

        case SEND_DATA_WAIT_ACK:
            break;

        default:
            break;
        }
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
