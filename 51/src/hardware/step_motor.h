#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H

#include "REG52.H"
 

extern unsigned char STEP; //���嵥������ ȫ�ֱ���

#define STEP_MOTOR_A A1
#define STEP_MOTOR_B A2
#define STEP_MOTOR_C B1
#define STEP_MOTOR_D B2

//=========== pin     set    ===============
sbit A1 = P0 ^ 0;
sbit A2 = P0 ^ 1;
sbit B1 = P0 ^ 2;
sbit B2 = P0 ^ 3;

//=========== funtion define ===============
#define f_STEP_MOTOR_INIT STEP_MOTOR_____
#define f_STEP_MOTOR_STOP STEP_MOTOR_OFF
#define f_STEP_SEEED_DELAY Delay

//============���ܺ���==================
void STEP_MOTOR_Init(void); //��ʼ��
void STEP_MOTOR_OFF(void);  //�ϵ�״̬
void STEP_MOTOR_8A( unsigned char a,  unsigned int speed);
void STEP_MOTOR_NUM( unsigned char dir,  unsigned int num,  unsigned char speed);  //�������������
void STEP_MOTOR_LOOP( unsigned char dir,  unsigned char LOOP,  unsigned char speed); //�����Ȧ������

#endif