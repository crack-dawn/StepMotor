/*
 * step_motor.c
 *
 *  Created on: 2023年3月23日
 *      Author: 23841
 */
//四相八拍
// STEP_0 A1_ON;   A2_OFF; B1_OFF; B2_OFF
// STEP_1 A1_ON;   A2_ON;  B1_OFF; B2_OFF
// STEP_2 A1_OFF;  A2_ON;  B1_OFF; B2_OFF
// STEP_3 A1_OFF;  A2_ON;  B1_ON;  B2_OFF
// STEP_4 A1_OFF;  A2_OFF; B1_ON;  B2_OFF
// STEP_5 A1_OFF;  A2_OFF; B1_ON;  B2_ON
// STEP_6 A1_OFF;  A2_OFF; B1_OFF; B2_ON
// STEP_7 A1_ON;   A2_OFF; B1_OFF; B2_ON

#include "step_motor.h"

struct  STEP_MOTOR_S StepMotorInfo;

void STEP_MOTOR_OFF(void) //电机断电 全拉低
{
    A1_OFF;  A2_OFF;  B1_OFF; B2_OFF;
}

//确定 步数拍数
void STEP_MOTOR_8A(u8 current_step) //电机单步8拍
{
    switch (current_step) {
        case 0:
            {A1_ON;   A2_OFF; B1_OFF; B2_OFF;}
            break;
        case 1:
             {A1_ON;   A2_ON;  B1_OFF; B2_OFF;}  
            break;
        case 2:
            {A1_OFF;  A2_ON;  B1_OFF; B2_OFF;}  
            break;
        case 3:
            {A1_OFF;  A2_ON;  B1_ON;  B2_OFF;}
            break;
        case 4:
            {A1_OFF;  A2_OFF; B1_ON;  B2_OFF;}
            break;
        case 5:
            {A1_OFF;  A2_OFF; B1_ON;  B2_ON;} 
            break;
        case 6:
            {A1_OFF;  A2_OFF; B1_OFF; B2_ON;}   
            break;
        case 7:
            {A1_ON;   A2_OFF; B1_OFF; B2_ON;}  
            break;
        default:
            break;
    }
}

//维持当前节拍位置
void STEP_MOTOR_MAINTAIN(u8 current_step)
{
    STEP_MOTOR_8A( current_step);
}

//转动一个节拍
void STEP_MOTOR_8A_RUN(u8 current_step, u16 speed)
{
    STEP_MOTOR_8A(current_step);
    delay_ms(2);  //延时
    STEP_MOTOR_OFF();
    // STEP_MOTOR_MAINTAIN(current_step);
}

//按照节拍数运行
void STEP_MOTOR_NUM(u8 RL, u16 StepNums, u16 speed) //电机按步数运行
{
    u16 i;
    for (i = 0; i < StepNums; i++)
    {
        if (RL == Front_Dir) { //当RL=Front_Dir右转，RL=Back__dir左转
            StepMotorInfo.step++;
            if (StepMotorInfo.step > 7)
            {
                StepMotorInfo.step = 0;
            }
        }
        else if(RL == Back__Dir)
        {
            if (StepMotorInfo.step == 0)
            {
                StepMotorInfo.step = 8;
            }
            StepMotorInfo.step--;
        }

        STEP_MOTOR_8A_RUN(StepMotorInfo.step, speed);
    }
}

//电机按圈数运行  需要先确定 一圈的节拍数  LOOP_STEP_NUMS
void STEP_MOTOR_LOOP(u8 RL, u8 LOOP,  u16 speed)
{
    STEP_MOTOR_NUM(RL, LOOP * LOOP_STEP_NUMS, speed);
}

//初始化管脚
void STEP_MOTOR_GPIO_Init(void)
{ //接口初始化
    P1DIR |= 0x3E; // 输出模式  8b' 0011_1110

    P1SEL |= 0xC1; // 使能为IO模式

    P1OUT &= 0x00; // 初始化电平拉低
}

