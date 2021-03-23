//---------------------------------------------
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ## @CPU:    STM32F030
// ##
// #### UART.H ################################
//---------------------------------------------
#ifndef __UART_H
#define __UART_H

// Module Exported Types Constants and Macros ----------------------------------

#define USART_9600		5000
#define USART_115200		416
#define USART_250000		192

#define USART1_CLK    (RCC->APB2ENR & 0x00004000)
#define USART1_CLK_ON    (RCC->APB2ENR |= 0x00004000)
#define USART1_CLK_OFF    (RCC->APB2ENR &= ~0x00004000)

#define USART2_CLK    (RCC->APB1ENR & 0x00020000)
#define USART2_CLK_ON    (RCC->APB1ENR |= 0x00020000)
#define USART2_CLK_OFF    (RCC->APB1ENR &= ~0x00020000)

#define USARTx_RX_DISA    (USARTx->CR1 &= 0xfffffffb)
#define USARTx_RX_ENA    (USARTx->CR1 |= 0x04)



// Module Exported Functions ---------------------------------------------------
void Usart1Config(void);
unsigned char Usart1ReadBuffer (unsigned char *, unsigned short);
void Usart1Send (char *);
void Usart1SendUnsigned(unsigned char *, unsigned char);
void Usart1SendSingle(unsigned char );
void USART1_IRQHandler(void);

#endif    /* __UART_H */

//--- end of file ---//

