//------------------------------------------------
// ## Internal Test Functions Module
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ##
// #### TEST_FUNCTIONS.C #########################
//------------------------------------------------

// Includes --------------------------------------------------------------------
#include "test_functions.h"
#include "stm32f0xx.h"
#include "hard.h"
#include "tim.h"
#include "uart.h"

#include <stdio.h>
// #include <string.h>



// Externals -------------------------------------------------------------------
extern volatile unsigned char usart1_have_data;

// Globals ---------------------------------------------------------------------


// Module Private Types & Macros -----------------------------------------------


// Module Private Functions ----------------------------------------------------


// Module Functions ------------------------------------------------------------
void TF_Usart1_Gpio_Input (void)
{
    Usart1Config();

    while (1)
    {
        if (S_BLUE)
        {
            Usart1SendSingle('b');
            Wait_ms(500);
        }
        if (S_GREEN)
        {
            Usart1SendSingle('g');
            Wait_ms(500);
        }
        if (S_RED)
        {
            Usart1SendSingle('r');
            Wait_ms(500);
        }
        if (S_COLD)
        {
            Usart1SendSingle('c');
            Wait_ms(500);
        }
        if (S_WARM)
        {
            Usart1SendSingle('w');
            Wait_ms(500);
        }
    }
}


void TF_Usart1_Multiple (void)
{
    Usart1Config();

    while (1)
    {
        Usart1Send("Mariano\n");
        Wait_ms(1000);
    }
}


void TF_Usart1_TxRx (void)
{
    Usart1Config();

    char s_to_send [100] = { 0 };
    Usart1Send("Ready to test...\n");
    while (1)
    {
        if (usart1_have_data)
        {
            usart1_have_data = 0;
            Usart1ReadBuffer((unsigned char *) s_to_send, 100);
            Wait_ms(1000);
            Usart1Send(s_to_send);
        }
    }
}


//--- end of file ---//
