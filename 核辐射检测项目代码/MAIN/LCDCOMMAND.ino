void updata(char sid, char cid, char data[]) //lcd更新文本控件的值
{
  char Str[] = {0X00, 0x00, 0X00};
  Str[0] = sid;
  Str[2] = cid;
  char head[] = {0XEE, 0XB1, 0X10, 0X00};
  char tail[] = {0XFF, 0XFC, 0XFF, 0XFF};

  float i;
  char s[4];             //IEEE4字节码转化为flaot型数
  s[3] = data[12];
  s[2] = data[11];
  s[1] = data[10];
  s[0] = data[9];

  float *pf = (float*)&s; //*pf便是转化后的10进制浮点数
  i = *pf;
  char bufdata[10];   //字符串存储数组

  sprintf(bufdata, "%f", i); //float to char

  Serial2.write(&head[0], 4);
  Serial2.write(&Str, 3);
  for (int i = 0; i < strlen(bufdata); i++)
  {
    Serial2.write(ASChex(bufdata[i]));
  }
  Serial2.write(&tail[0], 4);
}
void upCH(char sid, char cid, char q[])
{
  char Str[] = {0X00, 0x00, 0X00};
  Str[0] = sid;
  Str[2] = cid;
  char head[] = {0XEE, 0XB1, 0X10, 0X00};
  char tail[] = {0XFF, 0XFC, 0XFF, 0XFF};
  Serial2.write(&head[0], 4);
  Serial2.write(&Str, 3);
  for (int i = 0; i < strlen(q); i++)
  {
    Serial2.write(ASChex(q[i]));
  }
  Serial2.write(&tail[0], 4);
}
void uptem(char sid, char cid, char t) //温度
{
  char Str[] = {0X00, 0x00, 0X00};
  Str[0] = sid;
  Str[2] = cid;
  char head[] = {0XEE, 0XB1, 0X10, 0X00};
  char tail[] = {0XFF, 0XFC, 0XFF, 0XFF};
  char buftem[3];

  sprintf(buftem, "%d", t); //int（hex） to char
  Serial2.write(&head[0], 4);
  Serial2.write(&Str, 3);
  for (int i = 0; i < strlen(buftem); i++)
  {
    Serial2.write(ASChex(buftem[i]));
  }
  Serial2.write(&tail[0], 4);
}
void upstate(char sid, char cid, char s) //lcd更新文本控件的值
{
  switch (s)
  {
    case 0XE0://失效
      {
        char shixiao[15] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0XCA, 0XA7, 0XD0, 0XA7, 0XFF, 0XFC, 0XFF, 0XFF};
        shixiao[4] = sid;
        shixiao[6] = cid;
        Serial2.write(&shixiao[0], 15);
      } break;
    case 0XE4://失效
      {
        char shixiao[15] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0XCA, 0XA7, 0XD0, 0XA7, 0XFF, 0XFC, 0XFF, 0XFF};
        shixiao[4] = sid;
        shixiao[6] = cid;
        Serial2.write(&shixiao[0], 15);
      } break;
    case 0X60://二报，，，报警
      {
        char baojing[15] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0XB1, 0XA8, 0XBE, 0XAF, 0XFF, 0XFC, 0XFF, 0XFF};
        baojing[4] = sid;
        baojing[6] = cid;
        Serial2.write(&baojing[0], 15);
      } break;
    case 0X64://二报，，，报警
      {
        char baojing[15] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0XB1, 0XA8, 0XBE, 0XAF, 0XFF, 0XFC, 0XFF, 0XFF};
        baojing[4] = sid;
        baojing[6] = cid;
        Serial2.write(&baojing[0], 15);
      } break;
    case 0X40://一报，，，警告
      {
        char jinggao[15] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0XBE, 0XAF, 0XB8, 0XE6, 0XFF, 0XFC, 0XFF, 0XFF};
        jinggao[4] = sid;
        jinggao[6] = cid;
        Serial2.write(&jinggao[0], 15);
      } break;
    case 0X44://一报，，，警告
      {
        char jinggao[15] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0XBE, 0XAF, 0XB8, 0XE6, 0XFF, 0XFC, 0XFF, 0XFF};
        jinggao[4] = sid;
        jinggao[6] = cid;
        Serial2.write(&jinggao[0], 15);
      } break;
    case 0X00://正常
      {
        char normal[15] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0XD5, 0XFD, 0XB3, 0XA3, 0XFF, 0XFC, 0XFF, 0XFF};
        normal[4] = sid;
        normal[6] = cid;
        Serial2.write(&normal[0], 15);
      } break;
    case 0X04://正常
      {
        char normal[15] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0XD5, 0XFD, 0XB3, 0XA3, 0XFF, 0XFC, 0XFF, 0XFF};
        normal[4] = sid;
        normal[6] = cid;
        Serial2.write(&normal[0], 15);
      } break;
    case 0X10://低报
      {
        char dibao[15] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0XB5, 0XCD, 0XB1, 0XA8, 0XFF, 0XFC, 0XFF, 0XFF};
        dibao[4] = sid;
        dibao[6] = cid;
        Serial2.write(&dibao[0], 15);
      } break;
    case 0X14://低报
      {
        char dibao[15] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0XB5, 0XCD, 0XB1, 0XA8, 0XFF, 0XFC, 0XFF, 0XFF};
        dibao[4] = sid;
        dibao[6] = cid;
        Serial2.write(&dibao[0], 15);
      } break;
  }
}
void upchar(char sid, char cid, int a) //lcd更新文本控件的值
{
  char Str[] = {0X00, 0x00, 0X00};
  Str[0] = sid;
  Str[2] = cid;
  char *C = (char*)&a;
  char c = *C;
  char buf[1];
  sprintf(buf, "%x", c);
  buf[0] = buf[0];
  char head[] = {0XEE, 0XB1, 0X10, 0X00};
  char tail[] = {0XFF, 0XFC, 0XFF, 0XFF};
  Serial2.write(&head[0], 4);
  Serial2.write(&Str, 3);
  Serial2.write(buf[0]);
  Serial2.write(&tail[0], 4);
}
void upR(char sid, char cid) //填充⚪
{
  char Str[] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0X2A, 0XFF, 0XFC, 0XFF, 0XFF};
  Str[4] = sid;
  Str[6] = cid;
  Serial2.write(&Str[0], 12);
}
void blankR(char sid, char cid) //填充⚪
{
  char Str[] = {0XEE, 0XB1, 0X10, 0X00, 0X00, 0X00, 0X00, 0X20, 0XFF, 0XFC, 0XFF, 0XFF};
  Str[4] = sid;
  Str[6] = cid;
  Serial2.write(&Str[0], 12);
}
void SwitchingSC(char sid)//lcd切换画面
{
  char Str[] = {0XEE, 0XB1, 0X00, 0X00, 0x00, 0XFF, 0XFC, 0XFF, 0XFF};
  Str[4] = sid;
  Serial2.write(&Str[0], 9);
}
void upPB(char sid, char cid, char PBvalue) //lcd更新进度条控件的值
{
  char Str[] = {0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00};
  Str[0] = sid;
  Str[2] = cid;
  Str[6] = PBvalue;
  char head[] = {0XEE, 0XB1, 0X10, 0X00};
  char tail[] = {0XFF, 0XFC, 0XFF, 0XFF};
  Serial2.write(&head[0], 4);
  Serial2.write(&Str[0], 7);
  Serial2.write(&tail[0], 4);
}
char ASChex(char a)   //字符转hex
{
  a-=0X00;
  return (a);
}
