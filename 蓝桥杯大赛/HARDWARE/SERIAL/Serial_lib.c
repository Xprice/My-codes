/***********串口**************/
// UART

#include "Serial_lib.h"
void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;	// 8位数据,可变波特率
	AUXR |= 0x40;	// 定时器1时钟为Fosc,即1T
	AUXR &= 0xFE;	// 串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;	// 设定定时器1为16位自动重装方式
	TL1 = 0xE0;		// 设定定时初值
	TH1 = 0xFE;		// 设定定时初值
	ET1 = 0;		// 禁止定时器1中断
	TR1 = 1;		// 启动定时器1
	ES = 1;         // 允许串口中断
	EA = 1;         // 开启总中断
}
void UARTInter() interrupt 4
{
	if (TI == 1)
	{
		TI = 0; // 手动清除中断标志
	}
	if (RI == 1)
	{
		RI = 0; // 手动清除中断标志
		SBUF = SBUF + 1;
	}
}