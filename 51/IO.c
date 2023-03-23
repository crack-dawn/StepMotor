/*------------------------------------------------------------------*/
/* --- STC MCU Limited ---------------------------------------------*/
/* --- STC89-90xx Series MCU IO Demo -------------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966----------------------*/
/* --- Web: www.STCMCU.com -----------------------------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/

//
//由于P0口为开漏模式,所以需要外接10K左右的上拉电阻才可以正常测试
//对于STC90C5xAD/STC9LEC5xAD系列,P4口的地址为 0C0H
//
//P4.5默认为ALE引脚,需要使用ISP下载软件将它编程为P4.5口才可正常测试
//

#include "reg51.h"

sbit P00 = P0^0;
sbit P01 = P0^1;
sbit P02 = P0^2;
sbit P03 = P0^3;
sbit P04 = P0^4;
sbit P05 = P0^5;
sbit P06 = P0^6;
sbit P07 = P0^7;
sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P13 = P1^3;
sbit P14 = P1^4;
sbit P15 = P1^5;
sbit P16 = P1^6;
sbit P17 = P1^7;
sbit P20 = P2^0;
sbit P21 = P2^1;
sbit P22 = P2^2;
sbit P23 = P2^3;
sbit P24 = P2^4;
sbit P25 = P2^5;
sbit P26 = P2^6;
sbit P27 = P2^7;
sbit P30 = P3^0;
sbit P31 = P3^1;
sbit P32 = P3^2;
sbit P33 = P3^3;
sbit P34 = P3^4;
sbit P35 = P3^5;
sbit P36 = P3^6;
sbit P37 = P3^7;

sfr P4   = 0xC0;
sbit P40 = P4^0;
sbit P41 = P4^1;
sbit P42 = P4^2;
sbit P43 = P4^3;


//sfr P4 = 0xc0;        //STC90C5xAD/STC9LEC5xAD系列

void delay()
{
    int i, j;

    for (i=0; i<1000; i++)
    for (j=0; j<500; j++);
}


void main()
{
    P10 = 0;
    delay();
    P10 = 1;
    P11 = 0;
    delay();
    P11 = 1;
    P12 = 0;
    delay();
    P12 = 1;
    P13 = 0;
    delay();
    P13 = 1;
    P14 = 0;
    delay();
    P14 = 1;
    P15 = 0;
    delay();
    P15 = 1;
    P16 = 0;
    delay();
    P16 = 1;
    P17 = 0;
    delay();
    P17 = 1;

    P30 = 0;
    delay();
    P30 = 1;
    P31 = 0;
    delay();
    P31 = 1;
    P32 = 0;
    delay();
    P32 = 1;
    P33 = 0;
    delay();
    P33 = 1;
    P34 = 0;
    delay();
    P34 = 1;
    P35 = 0;
    delay();
    P35 = 1;
    P36 = 0;
    delay();
    P36 = 1;
    P37 = 0;
    delay();
    P37 = 1;

    P20 = 0;
    delay();
    P20 = 1;
    P21 = 0;
    delay();
    P21 = 1;
    P22 = 0;
    delay();
    P22 = 1;
    P23 = 0;
    delay();
    P23 = 1;
    P24 = 0;
    delay();
    P24 = 1;
    P25 = 0;
    delay();
    P25 = 1;
    P26 = 0;
    delay();
    P26 = 1;
    P27 = 0;
    delay();
    P27 = 1;

    P00 = 0;
    delay();
    P00 = 1;
    P01 = 0;
    delay();
    P01 = 1;
    P02 = 0;
    delay();
    P02 = 1;
    P03 = 0;
    delay();
    P03 = 1;
    P04 = 0;
    delay();
    P04 = 1;
    P05 = 0;
    delay();
    P05 = 1;
    P06 = 0;
    delay();
    P06 = 1;
    P07 = 0;
    delay();
    P07 = 1;

    P40 = 0;
    delay();
    P40 = 1;
    P41 = 0;
    delay();
    P41 = 1;
    P42 = 0;
    delay();
    P42 = 1;
    P43 = 0;
    delay();
    P43 = 1;

    while (1)
    {
        P1 = 0x00;
        delay();
        P1 = 0xff;

        P3 = 0x00;
        delay();
        P3 = 0xff;

        P2 = 0x00;
        delay();
        P2 = 0xff;

        P0 = 0x00;
        delay();
        P0 = 0xff;

        P4 = 0x00;
        delay();
        P4 = 0xff;
    }
}

