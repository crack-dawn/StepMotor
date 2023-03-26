/*
 * step_motor.c
 *
 *  Created on: 2023��3��23��
 *      Author: 23841
 */


#include "step_motor.h"

struct  STEP_MOTOR_S StepMotorInfo;


void STEP_MOTOR_Init(void)
{ //�ӿڳ�ʼ��
    P1DIR |= 0x3E; // ���ģʽ  8b' 0011_1110

    P1SEL |= 0xC1; // ʹ��ΪIOģʽ

    P1OUT &= 0x00; // ��ʼ����ƽ����
}

void STEP_MOTOR_OFF(void) //����ϵ� ȫ����
{
    A1_OFF;  A2_OFF;  B1_OFF; B2_OFF;
}

// #define STEP_0 A1_ON;   A2_OFF; B1_OFF; B2_OFF 
// #define STEP_1 {A1_ON;   A2_ON;  B1_OFF; B2_OFF}  
// #define STEP_2 {A1_OFF;  A2_ON;  B1_OFF; B2_OFF}  
// #define STEP_3 {A1_OFF;  A2_ON;  B1_ON;  B2_OFF}
// #define STEP_4 {A1_OFF;  A2_OFF; B1_ON;  B2_OFF}
// #define STEP_5 {A1_OFF;  A2_OFF; B1_ON;  B2_ON} 
// #define STEP_6 {A1_OFF;  A2_OFF; B1_OFF; B2_ON}   
// #define STEP_7 {A1_ON;   A2_OFF; B1_OFF; B2_ON}   

void STEP_MOTOR_8A(u8 a, u16 speed) //�������8��
{
    switch (a) {
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
    delay_ms(2);  //��ʱ
    STEP_MOTOR_OFF();
}


void STEP_MOTOR_NUM(u8 RL, u16 num, u8 speed) //�������������
{
    u16 i;
    for (i = 0; i < num; i++) {
        if (RL == 1) { //��RL=1��ת��RL=0��ת
            StepMotorInfo.step++;
            if (StepMotorInfo.step > 7) StepMotorInfo.step = 0;
        } else {
            if (StepMotorInfo.step == 0) StepMotorInfo.step = 8;
            StepMotorInfo.step--;
        }
        STEP_MOTOR_8A(StepMotorInfo.step, speed);
    }
}

void STEP_MOTOR_LOOP(u8 RL, u8 LOOP, u8 speed) //�����Ȧ������
{
    STEP_MOTOR_NUM(RL, LOOP * 4076, speed);
}

/*
 * step_motor.c
 *
 *  Created on: 2023��3��23��
 *      Author: 23841
 */

#include "step_motor.h"

struct STEP_MOTOR_S StepMotorInfo;

void STEP_MOTOR_Init(void)
{                  //�ӿڳ�ʼ��
    P1DIR |= 0x3E; // ���ģʽ  8b' 0011_1110

    P1SEL |= 0xC1; // ʹ��ΪIOģʽ

    P1OUT &= 0x00; // ��ʼ����ƽ����
}

void STEP_MOTOR_OFF(void) //����ϵ� ȫ����
{
    A1_OFF;
    A2_OFF;
    B1_OFF;
    B2_OFF;
}

// #define STEP_0 A1_ON;   A2_OFF; B1_OFF; B2_OFF
// #define STEP_1 {A1_ON;   A2_ON;  B1_OFF; B2_OFF}
// #define STEP_2 {A1_OFF;  A2_ON;  B1_OFF; B2_OFF}
// #define STEP_3 {A1_OFF;  A2_ON;  B1_ON;  B2_OFF}
// #define STEP_4 {A1_OFF;  A2_OFF; B1_ON;  B2_OFF}
// #define STEP_5 {A1_OFF;  A2_OFF; B1_ON;  B2_ON}
// #define STEP_6 {A1_OFF;  A2_OFF; B1_OFF; B2_ON}
// #define STEP_7 {A1_ON;   A2_OFF; B1_OFF; B2_ON}

void STEP_MOTOR_8A(u8 a, u16 speed) //�������8��
{
    switch (a)
    {
    case 0:
    {
        A1_ON;
        A2_OFF;
        B1_OFF;
        B2_OFF;
    }
    break;
    case 1:
    {
        A1_ON;
        A2_ON;
        B1_OFF;
        B2_OFF;
    }
    break;
    case 2:
    {
        A1_OFF;
        A2_ON;
        B1_OFF;
        B2_OFF;
    }
    break;
    case 3:
    {
        A1_OFF;
        A2_ON;
        B1_ON;
        B2_OFF;
    }
    break;
    case 4:
    {
        A1_OFF;
        A2_OFF;
        B1_ON;
        B2_OFF;
    }
    break;
    case 5:
    {
        A1_OFF;
        A2_OFF;
        B1_ON;
        B2_ON;
    }
    break;
    case 6:
    {
        A1_OFF;
        A2_OFF;
        B1_OFF;
        B2_ON;
    }
    break;
    case 7:
    {
        A1_ON;
        A2_OFF;
        B1_OFF;
        B2_ON;
    }
    break;
    default:
        break;
    }
    delay_ms(2); //��ʱ
    STEP_MOTOR_OFF();
}

void STEP_MOTOR_NUM(u8 RL, u16 num, u8 speed) //�������������
{
    u16 i;
    for (i = 0; i < num; i++)
    {
        if (RL == 1)
        { //��RL=1��ת��RL=0��ת
            StepMotorInfo.step++;
            if (StepMotorInfo.step > 7)
                StepMotorInfo.step = 0;
        }
        else
        {
            if (StepMotorInfo.step == 0)
                StepMotorInfo.step = 8;
            StepMotorInfo.step--;
        }
        STEP_MOTOR_8A(StepMotorInfo.step, speed);
    }
}

void STEP_MOTOR_LOOP(u8 RL, u8 LOOP, u8 speed) //�����Ȧ������
{
    STEP_MOTOR_NUM(RL, LOOP * 4076, speed);
}
