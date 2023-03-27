/*
 * TIM_B.c
 *
 *  Created on: 2023��3��27��
 *      Author: 23841
 */

#include "TIM_B.h"


#define CIRCLE ((unsigned int)1044)


void TIM_B_init(void)
{
    // TASSEL_1 ACLK��32768Hz���Լ�TASSEL_2 SMCLK��1.045MHz��
    TB0CTL = TBSSEL__SMCLK | ID_0 | MC_1 | TBIE | TBCLR;

    TB0CCR0 = CIRCLE; //��������
    TB0CCTL0 = CCIE; //ʹ���ж� �ж�����
    TB0CTL &= ~TBIFG; // �����ʱ��1�жϱ�־λ
    TB0R = 0;
}



#pragma vector = TIMER0_B0_VECTOR  //������0 �������������ж�����
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
        TB0CTL &= ~TBIFG; // �����ʱ��0�жϱ�־λs
    }
}