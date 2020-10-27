#include "ds18b20.h"

//延时函数
void DSdelay(unsigned int t)
{
	uchar i;
  while(t--)
	for(i=0;i<12;i++);
}

//DS18B20初始化函数
bit init_ds18b20(void)
{
  bit initflag = 0;
  DQ = 1;
  DSdelay(12);
  DQ = 0;
  DSdelay(80); // 延时大于480us
  DQ = 1;
  DSdelay(10);  // 14
  initflag = DQ;     // initflag等于1初始化失败
  DSdelay(5);
  
  return initflag;
}

//通过单总线向从器件写一个字节
void wr_ds18b20(unsigned char byt)
{
  unsigned char i;
  for(i=0;i<8;i++)
  {
    DQ = 0;
    DQ = byt&0x01;
    DSdelay(5);
    DQ = 1;
    byt >>= 1;
  }
  DSdelay(5);
}

//通过单总线从从器件读一个字节
unsigned char rd_ds18b20(void)
{
  unsigned char i;
  unsigned char byt;
  
  for(i=0;i<8;i++)
  {
    DQ = 0;
    byt >>= 1;
    DQ = 1;
    if(DQ)
    {
      byt |= 0x80;
    }    
    DSdelay(5);
  }
  return byt;
}

//温度转换、读取及数据处理器函数
float rd_temperature(void)
{
	unsigned int temp;
  unsigned char low,high;
	float tempreturn;
  
  init_ds18b20();
  wr_ds18b20(0xCC);
  wr_ds18b20(0x44); //启动温度转换
  DSdelay(200);

  init_ds18b20();
  wr_ds18b20(0xCC);
  wr_ds18b20(0xBE); //读取寄存器
  
  low = rd_ds18b20(); //低字节
  high = rd_ds18b20(); //高字节
  
  temp = high<<4;
  temp |= (low>>4);
	
  tempreturn = temp*0.0625;
  return tempreturn;
}

//温度转换、读取及数据处理器函数
unsigned char rd_temp(void)
{
  unsigned char low,high;
  char temp;
  
  init_ds18b20();
  wr_ds18b20(0xCC);
  wr_ds18b20(0x44); //??????
  DSdelay(200);

  init_ds18b20();
  wr_ds18b20(0xCC);
  wr_ds18b20(0xBE); //?????
  
  low = rd_ds18b20(); //???
  high = rd_ds18b20(); //???
  
  temp = high<<4;
  temp |= (low>>4);
  
  return temp;
}
