#ifndef _DS1302_H
#define _DS1302_H

#include "stc15f2k60s2.h"
#include "intrins.h"

sbit SCK=P1^7;		
sbit SDA=P2^3;		
sbit RST = P1^3;   // DS1302复位

void Write_Ds1302(unsigned char  address,unsigned char dat );
void Write_Ds1302_Byte( unsigned char temp);
unsigned char Read_Ds1302_Byte( unsigned char address );
void sfm(unsigned char shi,unsigned char fen,unsigned char miao);//sfm(06,06,06);时 分 秒    
#endif
