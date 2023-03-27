/*
 * TIM_A.c
 *
 *  Created on: 2023骞�3鏈�26鏃�
 *      Author: 23841
 */

#include "TIM_A.h"

#define CIRCLE ((unsigned int)CPU_F/1000)


void TIM_A_init(void)
{
    // TASSEL_1 ACLK（32768Hz）以及TASSEL_2 SMCLK（1.045MHz）
    TA1CTL = TASSEL__SMCLK | ID_0 | MC_1 | TAIE | TACLR;

    TA1CCR0 = CIRCLE; //计数周期
    TA1CCTL0 = CCIE; //使能中断 中断允许
    TA1CTL &= ~TAIFG; // 清除定时器1中断标志位
    TA1R = 0;
}


#pragma vector = TIMER1_A0_VECTOR  //计数器0 基础计数器的中断向量
__interrupt void TIMER1_A0_ISR(void)
{
    static unsigned int cnt=0;
    if(TA1CTL&TAIFG)
    {
        cnt++;
        if(cnt == 1000-1)
        {
            cnt = 0;
            P1OUT ^= 0x3E;
        }
        TA1CTL &= ~TAIFG; // 清除定时器1中断标志位s
    }
}


