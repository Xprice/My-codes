#ifndef _DS18B20_H
#define _DS18B20_H

#include "stc15f2k60s2.h"
#include "intrins.h"

#ifndef uchar
#define uchar unsigned char
#endif

sbit DQ = P1^4;

bit init_ds18b20(void);          //DS18B20初始化函数   return initflag=0  OK
void DSdelay(unsigned int t);            //DELAY
void wr_ds18b20(unsigned char byt);   //WT 1BYTE
unsigned char rd_ds18b20(void);       //READ 1BYTE    return byt
float rd_temperature(void);//READ TEM        return temp;

#endif
