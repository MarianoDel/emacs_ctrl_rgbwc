//---------------------------------------------
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ## @CPU:    STM32F030
// ##
// #### GPIO.C ################################
//---------------------------------------------

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "gpio.h"
#include "hard.h"

// Module Configuration --------------------------------------------------------
#define GPIOA_ENABLE
#define GPIOB_ENABLE
//#define GPIOF_ENABLE

// End of Module Configuration -------------------------------------------------

//-------------------------------------------//
// @brief  GPIO configure.
// @param  None
// @retval None
//------------------------------------------//
void GPIO_Config (void)
{
    unsigned long temp;

    //--- MODER ---//
    //00: Input mode (reset state)
    //01: General purpose output mode
    //10: Alternate function mode
    //11: Analog mode

    //--- OTYPER ---//
    //These bits are written by software to configure the I/O output type.
    //0: Output push-pull (reset state)
    //1: Output open-drain

    //--- ORSPEEDR ---//
    //These bits are written by software to configure the I/O output speed.
    //x0: Low speed.
    //01: Medium speed.
    //11: High speed.
    //Note: Refer to the device datasheet for the frequency.

    //--- PUPDR ---//
    //These bits are written by software to configure the I/O pull-up or pull-down
    //00: No pull-up, pull-down
    //01: Pull-up
    //10: Pull-down
    //11: Reserved


    //--- GPIO A ---//
#ifdef GPIOA_ENABLE    
    if (!GPIOA_CLK)
        GPIOA_CLK_ON;

    temp = GPIOA->MODER;    //2 bits por pin
    temp &= 0xFFFF030F;    //PA2 PA3 alternative; PA5 - PA7 input
    temp |= 0x000000A0;    //
    GPIOA->MODER = temp;

    temp = GPIOA->OTYPER;	//1 bit por pin
    temp &= 0xFFFFFFFF;
    temp |= 0x00000000;
    GPIOA->OTYPER = temp;

    temp = GPIOA->OSPEEDR;	//2 bits por pin
    temp &= 0xFFFFFFFF;
    temp |= 0x00000000;		//low speed
    GPIOA->OSPEEDR = temp;

    temp = GPIOA->PUPDR;	//2 bits por pin
    temp &= 0xFFFF03FF;         //PA5 - PA7 pull up   
    temp |= 0x00005400;	
    GPIOA->PUPDR = temp;
#endif


    //--- GPIO B ---//
#ifdef GPIOB_ENABLE
    if (!GPIOB_CLK)
        GPIOB_CLK_ON;

    temp = GPIOB->MODER;    //2 bits por pin
    temp &= 0xFFFFFFF0;    //PB0 PB1 input
    temp |= 0x00000000;
    GPIOB->MODER = temp;

    temp = GPIOB->OTYPER;	//1 bit por pin
    temp &= 0xFFFFFFFF;
    temp |= 0x00000000;
    GPIOB->OTYPER = temp;

    temp = GPIOB->OSPEEDR;	//2 bits por pin
    temp &= 0xFFFFFFFF;
    temp |= 0x00000000;		//low speed
    GPIOB->OSPEEDR = temp;

    temp = GPIOB->PUPDR;    //2 bits por pin
    temp &= 0xFFFFFFF0;    //PB0 PB1 pull up
    temp |= 0x00000005;
    GPIOB->PUPDR = temp;
#endif

#ifdef GPIOF_ENABLE

    //--- GPIO F ---//
    if (!GPIOF_CLK)
        GPIOF_CLK_ON;

    temp = GPIOF->MODER;
    temp &= 0xFFFFFFFF;
    temp |= 0x00000000;
    GPIOF->MODER = temp;

    temp = GPIOF->OTYPER;
    temp &= 0xFFFFFFFF;
    temp |= 0x00000000;
    GPIOF->OTYPER = temp;

    temp = GPIOF->OSPEEDR;
    temp &= 0xFFFFFFFF;
    temp |= 0x00000000;
    GPIOF->OSPEEDR = temp;

    temp = GPIOF->PUPDR;
    temp &= 0xFFFFFFFF;
    temp |= 0x00000000;
    GPIOF->PUPDR = temp;

#endif


}

#if (defined WITH_OVERCURRENT_SHUTDOWN) && (defined WITH_AC_SYNC_INT)
inline void EXTIOff (void)
{
    EXTI->IMR &= ~0x00000130;
}

inline void EXTIOn (void)
{
    EXTI->IMR |= 0x00000130;
}
#elif defined WITH_OVERCURRENT_SHUTDOWN
inline void EXTIOff (void)
{
    EXTI->IMR &= ~0x00000030;
}

inline void EXTIOn (void)
{
    EXTI->IMR |= 0x00000030;
}
#elif defined WITH_AC_SYNC_INT
inline void EXTIOff (void)
{
    EXTI->IMR &= ~0x00000100;
}

inline void EXTIOn (void)
{
    EXTI->IMR |= 0x00000100;
}
#endif



//--- end of file ---//
