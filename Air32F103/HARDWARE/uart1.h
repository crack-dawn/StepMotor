#ifndef UART1_H
#define UART1_H

#include "air32f10x.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
    PA9 == TX
    PA10== RX
*/



void UART1_Configuration(uint32_t bound);

int SER_PutChar(int ch);


#endif  