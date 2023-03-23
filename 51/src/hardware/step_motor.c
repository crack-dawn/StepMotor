#include "step_motor.h"




struct MOTOR_  {
    /* data */
    unsigned char STEP;
    unsigned char ToltalSteps;
    unsigned char Dir;
    unsigned char Speed;
} ;

struct MOTOR_ Motor = {0, 0, 2, 0};

unsigned char STEP;

void Delay(){}

void STEP_MOTOR_Init(void)
{ //接口初始化

     
}


void STEP_MOTOR_OFF(void) //电机断电 全拉低
{
    STEP_MOTOR_A=0; // 
    STEP_MOTOR_B=0; // 
    STEP_MOTOR_C=0; // 
    STEP_MOTOR_D=0; // 
}

void STEP_MOTOR_8A( unsigned char step,  unsigned int speed) //电机单步8拍
{
    switch (step) {
        case 0:
            STEP_MOTOR_A = 1; // 
            STEP_MOTOR_B = 0; // 
            STEP_MOTOR_C = 0; // 
            STEP_MOTOR_D = 0; // 
            // GPIO_ResetBits(STEP_MOTOR_PORT, STEP_MOTOR_B | STEP_MOTOR_C | STEP_MOTOR_D); // 0
            // GPIO_SetBits(STEP_MOTOR_PORT, STEP_MOTOR_A);                                 // 1
            break;
        case 1:
            STEP_MOTOR_A = 1; // 
            STEP_MOTOR_B = 1; // 
            STEP_MOTOR_C = 0; // 
            STEP_MOTOR_D = 0; // 
            // GPIO_ResetBits(STEP_MOTOR_PORT, STEP_MOTOR_C | STEP_MOTOR_D); // 0
            // GPIO_SetBits(STEP_MOTOR_PORT, STEP_MOTOR_A | STEP_MOTOR_B);   // 1
            break;
        case 2:
            STEP_MOTOR_A = 0; // 
            STEP_MOTOR_B = 1; // 
            STEP_MOTOR_C = 0; // 
            STEP_MOTOR_D = 0; // 
            // GPIO_ResetBits(STEP_MOTOR_PORT, STEP_MOTOR_A | STEP_MOTOR_C | STEP_MOTOR_D); // 0
            // GPIO_SetBits(STEP_MOTOR_PORT, STEP_MOTOR_B);                                 // 1
            break;
        case 3:
            STEP_MOTOR_A = 0; // 
            STEP_MOTOR_B = 1; // 
            STEP_MOTOR_C = 1; // 
            STEP_MOTOR_D = 0; // 
            // GPIO_ResetBits(STEP_MOTOR_PORT, STEP_MOTOR_A | STEP_MOTOR_D); // 0
            // GPIO_SetBits(STEP_MOTOR_PORT, STEP_MOTOR_B | STEP_MOTOR_C);   // 1
            break;
        case 4:
            STEP_MOTOR_A = 0; // 
            STEP_MOTOR_B = 0; // 
            STEP_MOTOR_C = 1; // 
            STEP_MOTOR_D = 0; // 
            // GPIO_ResetBits(STEP_MOTOR_PORT, STEP_MOTOR_A | STEP_MOTOR_B | STEP_MOTOR_D); // 0
            // GPIO_SetBits(STEP_MOTOR_PORT, STEP_MOTOR_C);                                 // 1
            break;
        case 5:
            STEP_MOTOR_A = 0; // 
            STEP_MOTOR_B = 0; // 
            STEP_MOTOR_C = 1; // 
            STEP_MOTOR_D = 1; // 
            // GPIO_ResetBits(STEP_MOTOR_PORT, STEP_MOTOR_A | STEP_MOTOR_B); // 0
            // GPIO_SetBits(STEP_MOTOR_PORT, STEP_MOTOR_C | STEP_MOTOR_D);   // 1
            break;
        case 6:
            STEP_MOTOR_A = 0; //
            STEP_MOTOR_B = 0; //
            STEP_MOTOR_C = 0; //
            STEP_MOTOR_D = 1; //
            // GPIO_ResetBits(STEP_MOTOR_PORT, STEP_MOTOR_A | STEP_MOTOR_B | STEP_MOTOR_C); // 0
            // GPIO_SetBits(STEP_MOTOR_PORT, STEP_MOTOR_D);                                 // 1
            break;
        case 7:
            STEP_MOTOR_A = 1; //
            STEP_MOTOR_B = 0; //
            STEP_MOTOR_C = 0; //
            STEP_MOTOR_D = 1; //
            // GPIO_ResetBits(STEP_MOTOR_PORT, STEP_MOTOR_B | STEP_MOTOR_C); // 0
            // GPIO_SetBits(STEP_MOTOR_PORT, STEP_MOTOR_A | STEP_MOTOR_D);   // 1
            break;
        default:
            break;
    }
    Delay();             //延时
    STEP_MOTOR_OFF(); //进入断电状态，防电机过热
}

void STEP_MOTOR_NUM( unsigned char dir,  unsigned int num,  unsigned char speed) //电机按步数运行
{
    unsigned int i;
    for (i = 0; i < num; i++) 
    {
        if (dir == 1) 
        { //当dir=1右转，dir=0左转
            STEP++;
            if (STEP > 7) STEP = 0;
        } 
        else 
        {
            if (STEP == 0) STEP = 8;
            STEP--;
        }
        STEP_MOTOR_8A(STEP, speed);
    }
}

void STEP_MOTOR_LOOP( unsigned char dir,  unsigned char LOOP,  unsigned char speed) //电机按圈数运行
{
    STEP_MOTOR_NUM(dir, LOOP * 4076, speed);
}