#include <stdint.h>
#include "reg.h"

// Transmit data register empty
#define USART_FLAG_TXE ((uint16_t) 0x0080)

int puts(const char *str) {
    while(*str) {
        //check TXE bit, if 0,not ready to write data into DR, otherwise write data into DR
        while (!(*(USART1_SR) & USART_FLAG_TXE)); 
        *(USART1_DR) = *str++ & 0xFF;
    }
    return 0;
}

void main(void) {
    
    //APB2 peripheral clock enable register 
    *(RCC_APB2ENR) |= (uint32_t) (1U<<0); //enable AFIOEN
    *(RCC_APB2ENR) |= (uint32_t) (1U<<2); //enable IOPAEN
    *(RCC_APB2ENR) |= (uint32_t) (1U<<14); //enable USART1EN


    //USART1 configuration
    *(GPIOA_CRL) = 0x44444444; //all PA0 to PA7:mode:00-> input, CNF:01 -> Floating input 
    
    *(GPIOA_CRH) = 0x444444B4;
    //seting PA9:TX,PA10:Rx
    //PA9: mode:11 -> output mode, max 50MHz, CNF:10 ->  Alternate-function push-pull
    //PA10 : mode:00 -> input mode, CNF:01 -> Floating input

    *(USART1_BRR) = 0x00000341;
    //DIV_Fraction:1
    //DIV_Mantissa:52
    //baud rate: 8000000 / (16 * (52+1/16)) = 9603.84 baud

    *(USART1_CR1) = 0x0000000C; //enable TE and RE
    *(USART1_CR1) |= 0x2000; //M: Word length 1 Start bit, 9 Data bits, n Stop bit

    puts("Hello,World!\n");

    while(1);
}
