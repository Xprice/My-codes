/*ADC*/
#include "ADDA_lib.h"
// [chl]选择通道
//AIN0---外接(0x00)   AIN1--光敏(0X01)       AIN2---放大器输出(0x02)     AIN3---电位器Rb2 (0X03)        
uchar ADC(uchar chl)
{
	uchar value;
	while (1)	// 等待设备应答
	{
		IIC_Start();
		IIC_SendByte(0x90);//write
		if (IIC_WaitAck()) break;
	}
	IIC_SendByte(chl);
	IIC_WaitAck();
	IIC_Stop();
	
	IIC_Start();
	IIC_SendByte(0x91);//read
	IIC_WaitAck();
	value = IIC_RecByte();  //获取到值
	IIC_SendAck(0);
	IIC_Stop();
	return value;	// 需转换为电压值
}
/*DAC*/
void DAC(uchar value)	// 输入值需要转换
{
	while (1)
	{
		IIC_Start();
		IIC_SendByte(0x90);
		if (IIC_WaitAck()) break;
	}
	IIC_SendByte(0x40);
	IIC_WaitAck();
	IIC_SendByte(value);
	IIC_WaitAck();
	IIC_Stop();
}