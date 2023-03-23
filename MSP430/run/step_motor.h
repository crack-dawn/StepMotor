/*
 * step_motor.h
 *
 *  Created on: 2023��3��23��
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

 

#define Delay_f(x)  delay_ms(x)

#define SM_STOP         (STEP_MOTOR_OFF)
extern u8 STEP; //���嵥������ ȫ�ֱ���

struct STEP_MOTOR_S{
    u8 step;            //һ�����ڲ���  ����
    u8 dir;             //��ת����
    u8 status;    //�˶� or ֹͣ
    u8 speed;       //  ������ ת���ٶ�
    u8 StepAngle; //������
    u8 SpeedDownRadio; //���ٱ�  ȡ����
    u8 NumOfPhase;       //��λ��
};

extern  struct  STEP_MOTOR_S StepMotorInfo;

#define STEP_MOTOR_PORT         GPIO_PORT_P1 //����IO�ӿ�������
#define STEP_MOTOR_A1           GPIO_PIN2 //����IO�ӿ�
#define STEP_MOTOR_A2           GPIO_PIN3 //����IO�ӿ�
#define STEP_MOTOR_B1           GPIO_PIN4 //����IO�ӿ�
#define STEP_MOTOR_B2           GPIO_PIN5 //����IO�ӿ�
 

#define A1_ON   GPIO_setOutputHighOnPin(STEP_MOTOR_PORT, STEP_MOTOR_A1)
#define A1_OFF  GPIO_setOutputLowOnPin(STEP_MOTOR_PORT, STEP_MOTOR_A1)

#define A2_ON   GPIO_setOutputHighOnPin(STEP_MOTOR_PORT, STEP_MOTOR_A2)
#define A2_OFF  GPIO_setOutputLowOnPin(STEP_MOTOR_PORT, STEP_MOTOR_A2)

#define B1_ON   GPIO_setOutputHighOnPin(STEP_MOTOR_PORT, STEP_MOTOR_B1)
#define B1_OFF  GPIO_setOutputLowOnPin(STEP_MOTOR_PORT, STEP_MOTOR_B1)

#define B2_ON   GPIO_setOutputHighOnPin(STEP_MOTOR_PORT, STEP_MOTOR_B2)
#define B2_OFF  GPIO_setOutputLowOnPin(STEP_MOTOR_PORT, STEP_MOTOR_B2)

 

// #define STEP_MOTOR_CLK  RCC_APB2Periph_GPIOA

void STEP_MOTOR_Init(void); //��ʼ��
void STEP_MOTOR_OFF(void);  //�ϵ�״̬
void STEP_MOTOR_8A(u8 a, u16 speed);
void STEP_MOTOR_NUM(u8 RL, u16 num, u8 speed);  //�������������
void STEP_MOTOR_LOOP(u8 RL, u8 LOOP, u8 speed); //�����Ȧ������

#endif
