#ifndef __REG_H_
#define __REG_H_

#define __REG_TYPE volatile uint32_t
#define __REG __REG_TYPE *

//RCC memory map
#define RCC     ((__REG_TYPE) 0x40021000)
#define RCC_APB2ENR ((__REG) (RCC + 0x18))
#define RCC_APB1ENR ((__REG) (RCC + 0x1C))

//GPIO memory map
#define GPIOA   ((__REG_TYPE) 0x4001_0800)
#define GPIOA_CRL ((__REG) (GPIOA + 0x00))
#define GPIOA_CRH ((__REG) (GPIOA + 0x04))

//USART1 memory map
#define USART1  ((__REG_TYPE) 0x40013800)
#define USART1_SR ((__REG) (USART1 + 0x00)) //status register
#define USART1_DR ((__REG) (USART1 + 0X04)) //data register
#define USART1_BRR	((__REG) (USART1 + 0x08)) //baud rate register
#define USART1_CR1	((__REG) (USART1 + 0x0C)) //Control register 1 



#endif