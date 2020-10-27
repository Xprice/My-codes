void setup() {
   Serial.begin(9600);
   Serial1.begin(9600);
}
char ASChex(char a)
{
  char b;
  if(a>=0X30&&a<=0X39)
  {b=a-0X00;}
  if(a>=0X20&&a<=0X2F)
  {b=0X2E;}
  return (b);
}
void lcdprint(byte data[])//实时数据解析
{
   float i;
   byte s[4];             //IEEE4字节码转化为flaot型数
   s[3]=data[12];
   s[2]=data[11];
   s[1]=data[10];
   s[0]=data[9];
   float *pf=(float*)&s;  //*pf便是转化后的10进制浮点数
   i=*pf;
   char buf[10];   //字符串存储数组
   sprintf(buf,"%f",i);   //float to char 
   for(int i=0;i<strlen(buf);i++)
   {
      Serial.print("ASChex");
      Serial1.write(ASChex(buf[i]));
   }
}
void loop() {  
   byte data[14]={0x01,0x02,0x03,0x04,0x01,0x02,0x03,0x04,0x01,/**/0x20,0xF0,0xC0,0x37,0x03};  
   lcdprint(data);
}
