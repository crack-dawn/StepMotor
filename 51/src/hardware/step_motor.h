#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H

#include "REG52.H"
 

extern unsigned char STEP; //定义单步计数 全局变量

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

//============功能函数==================
void STEP_MOTOR_Init(void); //初始化
void STEP_MOTOR_OFF(void);  //断电状态
void STEP_MOTOR_8A( unsigned char a,  unsigned int speed);
void STEP_MOTOR_NUM( unsigned char dir,  unsigned int num,  unsigned char speed);  //电机按步数运行
void STEP_MOTOR_LOOP( unsigned char dir,  unsigned char LOOP,  unsigned char speed); //电机按圈数运行

#endif