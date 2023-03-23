

#include "TIM3.h"
#include "main.h"


#ifndef  PRINTF_LOG
#define PRINTF_LOG printf
#endif


void TIM3_Configuration(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能

    //定时器TIM3初始化
    TIM_TimeBaseStructure.TIM_Period = 10000-1;                                    //设置在下一 个更新事件装入活动的自动重装载寄存器周期的值
    TIM_TimeBaseStructure.TIM_Prescaler = 7200-1;  //clocks.PCLK1_Frequency / 1000000 - 1;  //设置用来作为TIMx时钟频率 72_000_000除数的预分频值
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                     //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;                 // TIM向上计数模式
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);                             //根据指定的参数初始化TIMx的时间基数单位

    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE); //使能指定的TIM3中断,允许更新中断

    //中断优先级NVIC设置
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;           // TIM3中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //先占优先级0级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;        //从优先级3级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // IRQ通道被使能
    NVIC_Init(&NVIC_InitStructure);                           //初始化NVIC寄存器

    TIM_Cmd(TIM3, ENABLE); //使能TIMx
}


//定时器3中断服务程序
void TIM3_IRQHandler(void) // TIM3中断
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查TIM3更新中断发生与否
    {
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update); //清除TIMx更新中断标志
        PRINTF_LOG("%s\n", __FUNCTION__);
    }
}

