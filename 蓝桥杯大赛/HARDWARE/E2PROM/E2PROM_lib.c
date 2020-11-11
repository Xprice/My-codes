/**********EEPROM*********
单字节读写
/EEPROM 设备地址 0xA0写     0XA1读
**************************/

#include "E2PROM_lib.h"
#define devAddr 0xA0

void writeByte(uchar addr,uchar byt)
{
	IIC_Start();
	IIC_SendByte(devAddr);
	IIC_WaitAck();
	IIC_SendByte(addr);
	IIC_WaitAck();
	IIC_SendByte(byt);
	IIC_WaitAck();
	IIC_Stop();
}
uchar readByte(uchar addr)
{
	uchar dat;
	IIC_Start();
	IIC_SendByte(devAddr);
	IIC_WaitAck();
	IIC_SendByte(addr);
	IIC_WaitAck();
	IIC_Start();
	IIC_SendByte(devAddr | 0x01);
	IIC_WaitAck();
	dat = IIC_RecByte();
	IIC_SendAck(0);
	IIC_Stop();
	return dat;
}
/*多字节读写*/
// AT24C02 共 256 个字节 分为 8 页 共 32 页
// 页写入
void write(uchar addr, uchar len, uchar *arr)
{
	while (len > 0)
	{
		while (1)
		{
			IIC_Start();
			IIC_SendByte(devAddr);
			if (IIC_WaitAck()) break;
		}
		IIC_SendByte(addr);
		IIC_WaitAck();
		while (len > 0)
		{
			IIC_SendByte(*arr++);
			IIC_WaitAck();
			len--;
			addr++;
			// 判断是否达到页边界
			if ((addr & 0x07) == 0) break;
		}
		IIC_Stop();
	}
}

void read(uchar addr, uchar len, uchar *arr)
{
	while (1)
	{
		IIC_Start();
		IIC_SendByte(devAddr);
		if (IIC_WaitAck()) break;
	}
	IIC_SendByte(addr);
	IIC_WaitAck();
	IIC_Start();
	IIC_SendByte(devAddr | 0x01);
	IIC_WaitAck();
	while (--len)
	{
		*arr++ = IIC_RecByte();
		IIC_SendAck(1);
	}
	*arr = IIC_RecByte();
	IIC_SendAck(0);
	IIC_Stop();
}
