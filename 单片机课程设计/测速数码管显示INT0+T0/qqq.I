
#line 1 "qqq.c" /0
 
 
 
 
  
#line 1 "D:\Keil\3\C51\Inc\reg51.h" /0






 
 
 
 
 
 
 sfr P0   = 0x80;
 sfr P1   = 0x90;
 sfr P2   = 0xA0;
 sfr P3   = 0xB0;
 sfr PSW  = 0xD0;
 sfr ACC  = 0xE0;
 sfr B    = 0xF0;
 sfr SP   = 0x81;
 sfr DPL  = 0x82;
 sfr DPH  = 0x83;
 sfr PCON = 0x87;
 sfr TCON = 0x88;
 sfr TMOD = 0x89;
 sfr TL0  = 0x8A;
 sfr TL1  = 0x8B;
 sfr TH0  = 0x8C;
 sfr TH1  = 0x8D;
 sfr IE   = 0xA8;
 sfr IP   = 0xB8;
 sfr SCON = 0x98;
 sfr SBUF = 0x99;
 
 
 
 
 sbit CY   = 0xD7;
 sbit AC   = 0xD6;
 sbit F0   = 0xD5;
 sbit RS1  = 0xD4;
 sbit RS0  = 0xD3;
 sbit OV   = 0xD2;
 sbit P    = 0xD0;
 
 
 sbit TF1  = 0x8F;
 sbit TR1  = 0x8E;
 sbit TF0  = 0x8D;
 sbit TR0  = 0x8C;
 sbit IE1  = 0x8B;
 sbit IT1  = 0x8A;
 sbit IE0  = 0x89;
 sbit IT0  = 0x88;
 
 
 sbit EA   = 0xAF;
 sbit ES   = 0xAC;
 sbit ET1  = 0xAB;
 sbit EX1  = 0xAA;
 sbit ET0  = 0xA9;
 sbit EX0  = 0xA8;
 
 
 sbit PS   = 0xBC;
 sbit PT1  = 0xBB;
 sbit PX1  = 0xBA;
 sbit PT0  = 0xB9;
 sbit PX0  = 0xB8;
 
 
 sbit RD   = 0xB7;
 sbit WR   = 0xB6;
 sbit T1   = 0xB5;
 sbit T0   = 0xB4;
 sbit INT1 = 0xB3;
 sbit INT0 = 0xB2;
 sbit TXD  = 0xB1;
 sbit RXD  = 0xB0;
 
 
 sbit SM0  = 0x9F;
 sbit SM1  = 0x9E;
 sbit SM2  = 0x9D;
 sbit REN  = 0x9C;
 sbit TB8  = 0x9B;
 sbit RB8  = 0x9A;
 sbit TI   = 0x99;
 sbit RI   = 0x98;
 
 
#line 5 "qqq.c" /0
 
 unsigned char f,x;
 int UNIT,DECADE,v,t;
 unsigned char code C[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F,0X40}; 
 
 void delay(int i)        
 {
 int q;
 for(q=0;q<i;q++)
 {
 unsigned char a,b;    
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
 void NiXie_light(int num) 
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
 void InitTimer0(void) 
 {
 TMOD = 0x01;
 TH0 = 0x0FE;
 TL0 = 0x0C;
 EA = 1;
 ET0 = 1;
 TR0 = 1;
 }
 void InitINT0() 
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
 void Timer0Interrupt(void) interrupt 1     
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
 if(x<20){cout();NiXie_light(1);} 
 if(x>20){cout();NiXie_light(7);}
 }		
 }
