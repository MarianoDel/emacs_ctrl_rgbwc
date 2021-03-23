//---------------------------------------------
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ## @CPU:    STM32F030
// ##
// #### HARD.H ################################
//---------------------------------------------
#ifndef _HARD_H_
#define _HARD_H_

//----------- Defines For Configuration -------------
//----------- Hardware Board Version -------------


//---- Configuration for Hardware Versions -------




// Gpios Config --------------------------------------------
//GPIOA pin0    NC
//GPIOA pin1    NC

//GPIOA pin2    Usart Tx
//GPIOA pin3    Usart Rx

//GPIOA pin4    NC

//GPIOA pin5
#define S_BLUE    ((GPIOA->IDR & 0x0020) == 0)

//GPIOA pin6
#define S_GREEN    ((GPIOA->IDR & 0x0040) == 0)

//GPIOA pin7
#define S_RED    ((GPIOA->IDR & 0x0080) == 0)

//GPIOB pin0
#define S_COLD    ((GPIOB->IDR & 0x0001) == 0)

//GPIOB pin1
#define S_WARM   ((GPIOB->IDR & 0x0002) == 0)

//GPIOA pin8	
//GPIOA pin9
//GPIOA pin10
//GPIOA pin11
//GPIOA pin12
//GPIOA pin13 
//GPIOA pin14
//GPIOA pin15    NC

//GPIOB pin3
//GPIOB pin4
//GPIOB pin5
//GPIOB pin6
//GPIOB pin7	NC


// End of Gpios Config -------------------------------------


    
#endif /* _HARD_H_ */
