/************EEPROM*******#include <iic.h>!!!
******************************************/

#ifndef _E2PROM_LIB_H_
#define _E2PROM_LIB_H_

#include "iic.h"

#ifndef uchar
#define uchar unsigned char
#endif

/******************************************
单字节读写   EEPROM 设备地址 
******************************************/
void writeByte(uchar addr, uchar byt);
uchar readByte(uchar addr);

/******************************
多字节读写   AT24C02 共 256 个字节 分为 8 页 共 32 页
// 页写入
***********************/
void write(uchar addr, uchar len, uchar *arr);
void read(uchar addr, uchar len, uchar *arr);

#endif
