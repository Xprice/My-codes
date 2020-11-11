/**********************************************************************
矩阵键盘扫描******* 返回按键值，如无按键按下则返回 0**
   delayms.h!!!!!!!!!!!!!!!!!!!!!!
 矩阵键盘
 IAP15 芯片的 WR/RD 功能不是 P36/P37 引脚功能，故用 P42/P44 引脚代替
 即：P3^6 => P42  P3^7 => P44
***********************************************************************/

#ifndef __KEYPAD_LIB_H_
#define __KEYPAD_LIB_H_

#include "stc15f2k60s2.h"
#include "Delayms_lib.h"

#ifndef uchar
#define uchar unsigned char
#endif

uchar keyScan(void);

#endif