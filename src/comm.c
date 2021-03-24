//-----------------------------------------------------------------
// #### COLOR CONTROL BOARD RGBWC PROJECT  F030 - Custom Board ####
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ##
// #### COMM.C ####################################################
//-----------------------------------------------------------------

// Includes --------------------------------------------------------------------
#include "comm.h"
#include "uart.h"

#include <string.h>
#include <stdio.h>



// Externals -------------------------------------------------------------------
extern unsigned char usart1_have_data;


// Globals ---------------------------------------------------------------------
char buffMessages [100];


// Module Private Functions ----------------------------------------------------
void InterpretarMsg (char *);


// Module Functions ------------------------------------------------------------
void UpdateCommunications (void)
{
    if (usart1_have_data)
    {
        usart1_have_data = 0;
        Usart1ReadBuffer((unsigned char *) buffMessages, sizeof(buffMessages));

        InterpretarMsg(buffMessages);
    }
}


unsigned char acknowledge = 0;
void InterpretarMsg (char * msg)
{
    //-- Only check acknowledge
    if (strncmp(msg, "ok", sizeof("ok") - 1) == 0)        
    {
        acknowledge |= 0x01;
    }

    else if (strncmp(msg, "nok", sizeof("nok") - 1) == 0)
    {
        acknowledge |= 0x02;
    }

    else
    {
        acknowledge |= 0x02;
    }
}


void CommFlushAck (void)
{
    acknowledge = 0;
}


unsigned char CommCheckOK (void)
{
    if (acknowledge & 0x01)
        return 1;
    else
        return 0;
}


unsigned char CommCheckNOK (void)
{
    if (acknowledge & 0x02)
        return 1;
    else
        return 0;
}

//--- end of file ---//
