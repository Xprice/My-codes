#include "PWM_lib.h"

void changePWM(uint fre, uchar dc)
{
	float HTime, LTime;
	float time = 1090000.0 / fre;	// 周期 = 10^6毫秒 / 频率(fre)
	LTime = (time * dc / 100) * 11059200 / 12 / 1000000;
	HTime = (time - LTime) * 11059200 / 12 / 1000000;
	if (dc <= 0 || dc >= 100 || fre <= 0)	
	{
		TC = 255;
		if (dc <= 0) PWM = 0;
		else PWM = 1;
		return;
	}
	
	// 计数计算
	if (65536 < HTime) HC = HTime / 65536;
	else HC = 0;
	TH0 = HTH = (65536 - HTime) / 256;
	TL0 = HTL = (uint) (65536 - HTime) % 256;
	if (65536 < LTime) LC = LTime / 65536;
	else LC = 0;
	LTH = (65536 - LTime) / 256;
	LTL = (uint) (65536 - LTime) % 256;
	
	// 初始化
	TH0 = TL0 = 0;
	TC = LC;
	if (HC != 0)
		TC = HC;
}

void startPWM(uint fre, uchar dc)
{
	// PWM 初始化
	PWM = 1;
	TC = HC = LC = 0;
	// 定时器初始化
	TMOD &= 0xf0;
	TMOD |= 0x01;
	changePWM(fre, dc);
	EA = 1;
	TF0 = 0;
	ET0 = 1;
	TR0 = 1;
}

void stopPWM()
{
	TR0 = 0;
	PWM = 1;
}

void PWMTimer() interrupt 1
{
	// 当占空比为 0 或 100 时保持电瓶不变
	if (TC == 255) return;
	
	if (!TC--)
	{
		if (PWM)
		{
			TH0 = HTH;
			TL0 = HTL;
			TC = HC;
		}
		else 
		{
			TH0 = LTH;
			TL0 = LTL;
			TC = LC;
		}
		PWM = ~PWM;
	}
}