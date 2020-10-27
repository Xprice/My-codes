#ifndef _PWM_LIB_H_
#define _PWM_LIB_H_

#include "stc15f2k60s2.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

sbit PWM = P1^0;	// PWM 输出口

uchar HTH, HTL;	// 高电平持续时间
uchar LTH, LTL;	// 低电平持续时间
// 高电平计数， 低电平计数， 定时计数
uchar HC, LC, TC;
bit PWMF = 1;	// PWM 标志

void changePWM(uint fre, uchar dc);
void startPWM(uint fre, uchar dc);
void stopPWM();
void PWMTimer();

#endif