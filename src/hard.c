//-----------------------------------------------------------------
// #### COLOR CONTROL BOARD RGBWC PROJECT  F030 - Custom Board ####
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ##
// #### HARD.C ####################################################
//-----------------------------------------------------------------
#include "hard.h"
#include "stm32f0xx.h"
#include "tim.h"


// Module Private Types & Macros -----------------------------------------------


// Externals -------------------------------------------------------------------


// Globals ---------------------------------------------------------------------
//for timers or timeouts
volatile unsigned char switches_timer = 0;


// Module Private Functions ----------------------------------------------------


// Module Functions ------------------------------------------------------------


void HARD_Timeouts (void)
{
    if (switches_timer)
        switches_timer--;
}




#define SWITCHES_ROOF    200    //1000 ms
#define SWITCHES_THRESHOLD_MIN	40    //200 ms
#define SWITCHES_TIMER_RELOAD    5


unsigned char s_red_cntr = 0;
unsigned char s_green_cntr = 0;
unsigned char s_blue_cntr = 0;
unsigned char s_warm_cntr = 0;
unsigned char s_cold_cntr = 0;

unsigned char Check_S_Red (void)
{
    if (s_red_cntr > SWITCHES_THRESHOLD_MIN)
        return 1;
    else
        return 0;
}


unsigned char Check_S_Green (void)
{
    if (s_green_cntr > SWITCHES_THRESHOLD_MIN)
        return 1;
    else
        return 0;
}


unsigned char Check_S_Blue (void)
{
    if (s_blue_cntr > SWITCHES_THRESHOLD_MIN)
        return 1;
    else
        return 0;
}


unsigned char Check_S_Warm (void)
{
    if (s_warm_cntr > SWITCHES_THRESHOLD_MIN)
        return 1;
    else
        return 0;
}


unsigned char Check_S_Cold (void)
{
    if (s_cold_cntr > SWITCHES_THRESHOLD_MIN)
        return 1;
    else
        return 0;
}


void UpdateSwitches (void)
{
    if (!switches_timer)
    {
        if (S_RED)
        {
            if (s_red_cntr < SWITCHES_ROOF)
                s_red_cntr++;
        }
        else
        {
            if (s_red_cntr > 10)
                s_red_cntr -= 10;
            else
                s_red_cntr--;
        }

        if (S_GREEN)
        {
            if (s_green_cntr < SWITCHES_ROOF)
                s_green_cntr++;
        }
        else
        {
            if (s_green_cntr > 10)
                s_green_cntr -= 10;
            else
                s_green_cntr--;
        }

        if (S_BLUE)
        {
            if (s_blue_cntr < SWITCHES_ROOF)
                s_blue_cntr++;
        }
        else
        {
            if (s_blue_cntr > 10)
                s_blue_cntr -= 10;
            else
                s_blue_cntr--;
        }

        if (S_WARM)
        {
            if (s_warm_cntr < SWITCHES_ROOF)
                s_warm_cntr++;
        }
        else
        {
            if (s_warm_cntr > 10)
                s_warm_cntr -= 10;
            else
                s_warm_cntr--;
        }

        if (S_COLD)
        {
            if (s_cold_cntr < SWITCHES_ROOF)
                s_cold_cntr++;
        }
        else
        {
            if (s_cold_cntr > 10)
                s_cold_cntr -= 10;
            else
                s_cold_cntr--;
        }
        
        
        switches_timer = SWITCHES_TIMER_RELOAD;
    }       
}



//--- end of file ---//


