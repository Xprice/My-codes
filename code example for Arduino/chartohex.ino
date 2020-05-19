void setup() {
Serial2.begin(9600);
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
char ASChex(char a)   //  0-9字符转hex
{
  a=a-0x00;
  return (a);
}
void loop() {
  upCH(0x01,0x01,"0.123456789abcABC");
}
