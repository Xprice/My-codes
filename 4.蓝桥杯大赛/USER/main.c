#include <stc15f2k60s2.h>
#include <ds18b20.h>
#include <Base_lib.h>
#include <Delayms_lib.h>
#include <smg_lib.h>
#include <Tinit_lib.h>
#include <Keypad_lib.h>
#include <stdio.h>

	
#define uchar unsigned char
#define uint unsigned int 


unsigned char rd_temp(void);
void Timer0Init(void);
void init();


void buzz();
void stunumSHOW();
void temSHOW();
uchar keyScan();

void swkey(void);

uchar T,cout;

void main()
{
	init();
	//Timer0Init();
	while(1)
		{
		  //temSHOW();
			//stunumSHOW();
			swkey();
		}
	
}

void swkey()
{
	uchar key = keyScan();
	
  if(key!=0)
	{
		buzz();
		shumaguan(0, key);
	}		
}
void stunumSHOW()
{	
			shumaguan(7, 1);			
			shumaguan(6, 9);		
			shumaguan(5, 0);		
			shumaguan(4, 3);		
			shumaguan(3, 4);		
			shumaguan(2, 1);			
			shumaguan(1, 1);		
			shumaguan(0, 7);
}

void temSHOW()
{	
	uchar ge,shi;
  if(cout==1000)
	{
		T	= rd_temp();
		cout=0;
	}
	
	shi= T/10;
	ge= T%10;
	
	shumaguan(7, shi);
	
	shumaguan(6, ge);
}
//void T0Interrupt()	interrupt 1     //
//{
//	TH0 = 0x0D1;
//  TL0 = 0x20;
//  //add your code here!
//	cout++;
//}
void buzz()
{
	select(5);
	P0 = 0xff;//Ïì
	delayms(200);
	P0 = 0x00;
}