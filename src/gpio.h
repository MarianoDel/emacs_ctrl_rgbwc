//---------------------------------------------
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ## @CPU:    STM32F030
// ##
// #### GPIO.H ################################
//---------------------------------------------
#ifndef _GPIO_H_
#define _GPIO_H_


// Exported Types Constants and Macros -----------------------------------------
#define GPIOA_CLK    (RCC->AHBENR & 0x00020000)
#define GPIOA_CLK_ON    (RCC->AHBENR |= 0x00020000)
#define GPIOA_CLK_OFF    (RCC->AHBENR &= ~0x00020000)

#define GPIOB_CLK    (RCC->AHBENR & 0x00040000)
#define GPIOB_CLK_ON    (RCC->AHBENR |= 0x00040000)
#define GPIOB_CLK_OFF    (RCC->AHBENR &= ~0x00040000)

#define GPIOC_CLK    (RCC->AHBENR & 0x00080000)
#define GPIOC_CLK_ON    (RCC->AHBENR |= 0x00080000)
#define GPIOC_CLK_OFF    (RCC->AHBENR &= ~0x00080000)

#define GPIOD_CLK    (RCC->AHBENR & 0x00100000)
#define GPIOD_CLK_ON    (RCC->AHBENR |= 0x00100000)
#define GPIOD_CLK_OFF    (RCC->AHBENR &= ~0x00100000)

#define GPIOF_CLK    (RCC->AHBENR & 0x00400000)
#define GPIOF_CLK_ON    (RCC->AHBENR |= 0x00400000)
#define GPIOF_CLK_OFF    (RCC->AHBENR &= ~0x00400000)

#define SYSCFG_CLK    (RCC->APB2ENR & 0x00000001)
#define SYSCFG_CLK_ON    (RCC->APB2ENR |= 0x00000001)
#define SYSCFG_CLK_OFF    (RCC->APB2ENR &= ~0x00000001)

// Module Exported Functions ---------------------------------------------------
void GPIO_Config(void);
void EXTIOff (void);
void EXTIOn (void);

#endif    /* _GPIO_H_ */


//--- end of file ---//
