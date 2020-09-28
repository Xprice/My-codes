/*   sbit a0=P1^7; a1=P1^6;a2=P1^5;a3=P1^4;a4=P1^3;       BLANK=P1^2;//BLANK--C[10]     S0=P1^1;//decade    S1=P1^0;//unit   */



#include "reg51.h"     //P0 is the order number of NIXIE LIGHT     P1 is the HEX code of NIXIE LIGHT 
unsigned char f,x;
int UNIT,DECADE,v,t;
unsigned char code C[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F,0X40};//HEX code for 0-9 
//unsigned char code C2[]={0XBF,0X86,0XDB,0XCF,0XE6,0XED,0XFD,0X87,0XFF,0XEF};//HEX code with radix point for 0-9 
void delay(int i)       //[i]ms
{
	int q;
	for(q=0;q<i;q++)
	{
    unsigned char a,b;   //1ms
    for(b=71;b>0;b--)
        for(a=2;a>0;a--);
	}
}
void delay500us()   
{
    unsigned char a,b;
    for(b=19;b>0;b--)
        for(a=5;a>0;a--);
}
void NiXie_light(int num)//'num' --- Student ID
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		switch(i)
		{
			case 0: P1=0X7F;
					    P0=C[3];
					    delay500us();
					    P0=0X00;
			break;
			case 1: P1=0XBF;
				    	P0=C[4];
			    	  delay500us();
			      	P0=0X00;
			break;
			
			case 2: P1=0XDF;
				    	P0=C[1];
			    	  delay500us();
			      	P0=0X00;
			break;
			case 3: P1=0XEF;
				    	P0=C[1];
			    	  delay500us();
			      	P0=0X00;
			break;
			case 4: P1=0XF7;
				    	P0=C[num];
			    	  delay500us();
			      	P0=0X00;
			break;
			case 5: P1=0XFB;
				    	P0=C[10];
			    	  delay500us();
			      	P0=0X00;
			break;
			case 6: P1=0XFD;
				    	P0=C[DECADE];
			    	  delay500us();
			      	P0=0X00;
			break;
      case 7: P1=0XFE;
				    	P0=C[UNIT];
			    	  delay500us();
			      	P0=0X00;
			break;
		}
	}
}
void InitTimer0(void)//T0's initialization 
{
    TMOD = 0x01;
    TH0 = 0x0FE;
    TL0 = 0x0C;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
void InitINT0()//INT0's initialization 
{
	IT0=1;
	EX0=1;
	EA=1;
}
void INT0Interrupt()	interrupt 0
{
	EX0=0;
	f++;
	x++;
	if(f==7)
	{
		TR0=0;
		v=3500/t;
	  t=0;
		f=0;
		ET0=1;
	  TR0=1;
	}
	EX0=1;
}
void Timer0Interrupt(void) interrupt 1    //1MS
{
    TH0 = 0x0FE;
    TL0 = 0x0C;
    t++;
}
void cout()
{
	if(x==40){x=0;}
	UNIT=(v%10);
	DECADE=(v/10);
}
void main()
{
	InitINT0();
  InitTimer0();
	while(1)
	{
		if(x<20){cout();NiXie_light(1);}//Change student number every 10 laps
		if(x>20){cout();NiXie_light(7);}
	}		
}
