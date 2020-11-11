/***************定时器初始化***************/
#include "Tinit_lib.h"
/*T0*/
void Timer0Init(void)   // 10 毫秒 @11.0592MHz
{
	AUXR &= 0x7F;	// 定时器时钟 12T 模式
	TMOD &= 0xF0;	// 设置定时器模式
	TL0 = 0x00;		// 设置定时初值
	TH0 = 0xDC;		// 设置定时初值
	TF0 = 0;		// 清除 TF0 标志
	TR0 = 1;		// 定时器 0 开始计时

	EA = 1;
	ET0 = 1;
}
/*T1*/
void Timer1Init(void)   // 10 毫秒 @11.0592MHz
{
	AUXR &= 0xBF;	// 定时器时钟 12T 模式
	TMOD &= 0x0F;	// 设置定时器模式
	TL1 = 0x00;		// 设置定时初值
	TH1 = 0xDC;		// 设置定时初值
	TF1 = 0;		// 清除 TF1 标志
	TR1 = 1;		// 定时器 1 开始计时

	EA = 1;
	ET1 = 1;
}
/*T2*/
void Timer2Init(void)   // 10 毫秒 @11.0592MHz
{
	AUXR &= 0xFB;	// 定时器时钟 12T 模式
	T2L = 0x00;		// 设置定时初值
	T2H = 0xDC;		// 设置定时初值
	AUXR |= 0x10;   // 定时器 2 开始计时

	EA = 1;
	IE2 |= 0x04;
}