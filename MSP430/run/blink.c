#include <msp430.h>
#include "driverlib.h"
#include "step_motor.h"
#include "TIM_A.h"

void SYS_Initialize()
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    __enable_interrupt(   ); //开启全局总中断 允许

}

void GPIO_Configure()
{
    P1DIR |= 0x3E;  // 输出模式  8b' 0011_1110

    P1SEL |= 0xC1;  // 使能为IO模式

    P1OUT &= 0x00;  // 初始化电平拉低
}


/**
 * blink.c
 */
void main(void)
{
   SYS_Initialize();
   GPIO_Configure();
   //TIM_A_init();

   StepMotorInfo.step=0;
//   for(StepMotorInfo.step = 0 ; StepMotorInfo.step < 8 ; StepMotorInfo.step++)
//   {
//       STEP_MOTOR_8A_RUN(StepMotorInfo.step, 10);
//       delay_ms(100);
//   }

    while (1)
   {
    STEP_MOTOR_NUM(1,3000,10);
   }
}













