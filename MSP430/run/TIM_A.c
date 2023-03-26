/*
 * TIM_A.c
 *
 *  Created on: 2023年3月26日
 *      Author: 23841
 */

#include "TIM_A.h"

void TIM_A_init(void)
{
    Timer_A_initUpModeParam TIMA_init_struct;
    TIMA_init_struct.clockSource=
    TIMA_init_struct.clockSourceDivider=
    TIMA_init_struct.timerPeriod=
    TIMA_init_struct.timerInterruptEnable_TAIE=TIMER_A_TAIE_INTERRUPT_ENABLE;
    TIMA_init_struct.captureCompareInterruptEnable_CCR0_CCIE=TIMER_A_CCIE_CCR0_INTERRUPT_DISABLE;
    TIMA_init_struct.timerClear=TIMER_A_DO_CLEAR;
    TIMA_init_struct.startTimer=
    Timer_A_initUpMode(uint16_t baseAddress, Timer_A_initUpModeParam * param);
}
extern void 