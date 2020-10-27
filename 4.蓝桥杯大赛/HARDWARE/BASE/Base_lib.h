#ifndef __BASE_LIB_H_
#define __BASE_LIB_H_

#include "stc15f2k60s2.h"

#ifndef uchar
#define uchar unsigned char
#endif

extern void select(uchar num);//0锁存 4关闭LED灯 5关闭蜂鸣器 6选中全部数码管 7关闭数码管   
extern void init();//关闭LED灯、蜂鸣器、数码管

#endif