#include <msp430.h>
#include "driverlib.h"
#include "step_motor.h"


void SYS_Initialize()
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
//
}



void GPIO_Configure()
{
    P1DIR |= 0x3E;  // ���ģʽ  8b' 0011_1110

    P1SEL |= 0xC1;  // ʹ��ΪIOģʽ

    P1OUT &= 0x00;  // ��ʼ����ƽ����
}


/**
 * blink.c
 */
void main(void)
{

   SYS_Initialize();
   GPIO_Configure();


   while(1)
   {
       P1OUT ^= 0x3E;              // toggle P1.0
       delay_ms(1000);
       P1OUT ^= 0x3E;
       delay_ms(1000);
       STEP_MOTOR_LOOP(1, 2, 10);
   }
}
//
//void main()
//{
//    //Stop WDT
//    WDT_A_hold(WDT_A_BASE);
//    //P1.0Ϊ���
//    GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN0);
//    //P4.7Ϊ���
//    GPIO_setAsOutputPin(GPIO_PORT_P4,GPIO_PIN7);
//    while(1)
//    {
//        //��תP1.0��ƽ
//        GPIO_toggleOutputOnPin(GPIO_PORT_P4,GPIO_PIN7);
//        //P1.0����ߵ�ƽ
//        GPIO_setOutputHighOnPin(GPIO_PORT_P1,GPIO_PIN0);
//        delay_ms(1000);
//        //P1.0����͵�ƽ
//        GPIO_setOutputLowOnPin(GPIO_PORT_P1,GPIO_PIN0);
//        delay_ms(1000);
//    }
//}
//
//
//
//
//












