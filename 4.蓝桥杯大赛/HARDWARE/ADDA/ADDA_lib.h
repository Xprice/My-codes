#ifndef _ADDA_LIB_H_
#define _ADDA_LIB_H_

#include "stc15f2k60s2.h"
#include "iic.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

uchar ADC(uchar chl);// 形参是通道号   return转换后电压值

void DAC(uchar value);//输入值需要转换

#endif