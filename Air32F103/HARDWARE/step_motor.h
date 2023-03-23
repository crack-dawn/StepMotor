#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H
#include "air32f10x.h"
#include "delay.h"
 
#define Delay_f(x)  Delay_Ms(x)
#define SM_STOP			(STEP_MOTOR_OFF)
extern u8 STEP; //定义单步计数 全局变量

struct STEP_MOTOR_S{
	u8 step; 			//一周期内步数  相数
	u8 dir;  			//旋转方向
	u8 status;	  //运动 or 停止
	u8 speed; 		//  脉冲间隔 转动速度
	u8 StepAngle; //步进角
	u8 SpeedDownRadio; //减速比  取整数  
	u8 NumOfPhase; 		 //相位数
};

extern  struct  STEP_MOTOR_S StepMotorInfo;
 



#define STEP_MOTOR_PORT GPIOA      //定义IO接口所在组
#define STEP_MOTOR_A    GPIO_Pin_4 //定义IO接口
#define STEP_MOTOR_B    GPIO_Pin_6 //定义IO接口
#define STEP_MOTOR_C    GPIO_Pin_7 //定义IO接口
#define STEP_MOTOR_D    GPIO_Pin_5 //定义IO接口
#define STEP_MOTOR_CLK  RCC_APB2Periph_GPIOA

void STEP_MOTOR_Init(void); //初始化
void STEP_MOTOR_OFF(void);  //断电状态
unsigned char STEP_MOTOR_8A(u8 a, u16 speed);
void STEP_MOTOR_NUM(u8 RL, u16 num, u8 speed);  //电机按步数运行
void STEP_MOTOR_LOOP(u8 RL, u8 LOOP, u8 speed); //电机按圈数运行

#endif