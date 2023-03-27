/*
 * TIM_B.c
 *
 *  Created on: 2023年3月27日
 *      Author: 23841
 */

#include "TIM_B.h"


#define CIRCLE ((unsigned int)1044)


void TIM_B_init(void)
{
    // TASSEL_1 ACLK（32768Hz）以及TASSEL_2 SMCLK（1.045MHz）
    TB0CTL = TBSSEL__SMCLK | ID_0 | MC_1 | TBIE | TBCLR;

    TB0CCR0 = CIRCLE; //计数周期
    TB0CCTL0 = CCIE; //使能中断 中断允许
    TB0CTL &= ~TBIFG; // 清除定时器1中断标志位
    TB0R = 0;
}



#pragma vector = TIMER0_B0_VECTOR  //计数器0 基础计数器的中断向量
__interrupt void TIMER0_B0_ISR(void)
{
    static unsigned int cnt=0;
    if(TB0CTL&TBIFG)
    {
        cnt++;
        if(cnt == 1000-1)
        {
            cnt = 0;
            P1OUT ^= 0x3E;
        }
        TB0CTL &= ~TBIFG; // 清除定时器0中断标志位s
    }
}
