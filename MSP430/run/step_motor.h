/*
 * step_motor.h
 *
 *  Created on: 2023骞�3鏈�23鏃�
 *      Author: 23841
 */

#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H



//#include "delay.h"
#include <msp430.h>
#include "driverlib.h"

#ifndef u8
typedef unsigned char u8;
typedef unsigned int u16;
#endif

#define Delay_f(x) delay_ms(x)

#define SM_STOP (STEP_MOTOR_OFF())

struct STEP_MOTOR_S
{
    u8 step; //涓�鍛ㄦ湡鍐呮鏁�  鐩告暟
    long int totalsteps;
    u8 StepAngle;      //姝ヨ繘瑙�
    u8 dir;            //鏃嬭浆鏂瑰悜
    u8 status;         //杩愬姩 or 鍋滄
    u8 speed;          //  鑴夊啿闂撮殧 杞姩閫熷害
    u8 SpeedDownRadio; //鍑忛�熸瘮  鍙栨暣鏁�
};

extern struct STEP_MOTOR_S StepMotorInfo;

#define STEP_MOTOR_PORT GPIO_PORT_P1 //瀹氫箟IO鎺ュ彛鎵�鍦ㄧ粍
#define STEP_MOTOR_A1 GPIO_PIN2      //瀹氫箟IO鎺ュ彛
#define STEP_MOTOR_A2 GPIO_PIN3      //瀹氫箟IO鎺ュ彛
#define STEP_MOTOR_B1 GPIO_PIN4      //瀹氫箟IO鎺ュ彛
#define STEP_MOTOR_B2 GPIO_PIN5      //瀹氫箟IO鎺ュ彛

#define A1_ON GPIO_setOutputHighOnPin(STEP_MOTOR_PORT, STEP_MOTOR_A1)
#define A1_OFF GPIO_setOutputLowOnPin(STEP_MOTOR_PORT, STEP_MOTOR_A1)

#define A2_ON GPIO_setOutputHighOnPin(STEP_MOTOR_PORT, STEP_MOTOR_A2)
#define A2_OFF GPIO_setOutputLowOnPin(STEP_MOTOR_PORT, STEP_MOTOR_A2)

#define B1_ON GPIO_setOutputHighOnPin(STEP_MOTOR_PORT, STEP_MOTOR_B1)
#define B1_OFF GPIO_setOutputLowOnPin(STEP_MOTOR_PORT, STEP_MOTOR_B1)

#define B2_ON GPIO_setOutputHighOnPin(STEP_MOTOR_PORT, STEP_MOTOR_B2)
#define B2_OFF GPIO_setOutputLowOnPin(STEP_MOTOR_PORT, STEP_MOTOR_B2)



#define Front_Dir (0x01u)
#define Back__Dir (0x00u)

#define LOOP_STEP_NUMS (4076)
#define DELAY_



void STEP_MOTOR_Init(void); 

void STEP_MOTOR_OFF(void);   

void STEP_MOTOR_MAINTAIN(u8 current_step);

void STEP_MOTOR_8A_RUN(u8 current_step, u16 speed);

void STEP_MOTOR_NUM(u8 RL, u16 StepNums, u16 speed);  

void STEP_MOTOR_LOOP(u8 RL, u8 LOOP, u16 speed); 


#endif
