void N1BCC12(byte N, byte N1)           //经过BCC校验填补数组末尾校验位
{
for (int a = 0; a < 13; a++)
{
  N1com1[a][2] = N;
  N1com2[a][2] = N;
  N1com1[a][3] = N1;
  N1com2[a][3] = N1;
  int La = sizeof( N1com1[a]);
  int Lb = sizeof( N1com2[a]);
  byte X = N1com1[a][0];
  byte Y = N1com2[a][0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N1com1[a][b + 1];
  }
  N1com1[a][La - 1] = X;
  for (int b = 0; b < Lb - 1; b++)
  {
    Y ^= N1com2[a][b + 1];
  }
  N1com2[a][Lb - 1] = Y;
}
}
void N1BCC3(byte N, byte N1, byte BH1) //PC号，探头号，编号
{
N1com3[2] = N;
N1com3[3] = N1;
N1com3[5] = BH1;
int La = 6;
byte X = N1com3[0];
for (int b = 0; b < La - 1; b++)
{
  X ^= N1com3[b + 1];
}
N1com3[La - 1] = X;
}
void N1BCC4(byte N, byte N1, byte LC1) //******量程1-6
{
for (int a = 0; a < 5; a++)
{
  N1com4[a][2] = N;
  N1com4[a][3] = N1;
  N1com4[a][5] = LC1;
  int La = sizeof(N1com4[a]);
  byte X = N1com4[a][0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N1com4[a][b + 1];
  }
  N1com4[a][La - 1] = X;
}
}
void N1BCC5(byte N, byte N1, byte N1SJ1, byte N1SJ2, byte N1SJ3, byte N1SJ4) //****** 4组数据0X00-FF
{
for (int a = 0; a < 13; a++)
{
  N1com5[a][2] = N;
  N1com5[a][3] = N1;
  N1com5[a][5] = N1SJ1;
  N1com5[a][6] = N1SJ2;
  N1com5[a][7] = N1SJ3;
  N1com5[a][8] = N1SJ4;
  int La = sizeof(N1com5[a]);
  byte X = N1com5[a][0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N1com5[a][b + 1];
  }
  N1com5[a][La - 1] = X;
}
}
void N1BCC6(byte N, byte N1, byte N1SJ5, byte N1SJ6, byte N1SJ7, byte N1SJ8) //****** 4组数据0X00-FF
{
for (int a = 0; a < 4; a++)
{
  N1com6[a][2] = N;
  N1com6[a][3] = N1;
  N1com6[a][6] = N1SJ5;
  N1com6[a][7] = N1SJ6;
  N1com6[a][8] = N1SJ7;
  N1com6[a][9] = N1SJ8;
  int La = sizeof(N1com6[a]);
  byte X = N1com6[a][0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N1com6[a][b + 1];
  }
  N1com6[a][La - 1] = X;
}
}
void N1BCC7(byte N, byte N1, byte N1SJ9, byte N1SJ10, byte N1SJ11, byte N1SJ12, byte N1SJ13) //****** 4组数据0X00-FF
{
for (int a = 0; a < 4; a++)
{
  N1com7[a][2] = N;
  N1com7[a][3] = N1;
  N1com7[a][5] = N1SJ9;
  N1com7[a][6] = N1SJ10;
  N1com7[a][7] = N1SJ11;
  N1com7[a][8] = N1SJ12;
  N1com7[a][9] = N1SJ13;
  int La = sizeof(N1com7[a]);
  byte X = N1com7[a][0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N1com7[a][b + 1];
  }
  N1com7[a][La - 1] = X;
}
}
void N1BCC8(byte N, byte N1, byte N1SJ14, byte N1SJ15, byte N1SJ16, byte N1SJ17, byte N1SJ18, byte N1SJ19, byte N1SJ20, byte N1SJ21, byte N1SJ22) //PC号，探头号，编号
{
N1com8[2] = N;
N1com8[3] = N1;
N1com8[5] = N1SJ14;
N1com8[6] = N1SJ15;
N1com8[7] = N1SJ16;
N1com8[8] = N1SJ17;
N1com8[9] = N1SJ18;
N1com8[10] = N1SJ19;
N1com8[11] = N1SJ20;
N1com8[12] = N1SJ21;
N1com8[13] = N1SJ22;
int La = 15;
byte X = N1com8[0];
for (int b = 0; b < La - 1; b++)
{
  X ^= N1com8[b + 1];
}
N1com8[La - 1] = X;
}


void N2BCC12(byte N, byte N2)           //经过BCC校验填补数组末尾校验位
{
  for (int a = 0; a < 13; a++)
  {
    N2com1[a][2] = N;
    N2com2[a][2] = N;
    N2com1[a][3] = N2;
    N2com2[a][3] = N2;
    int La = sizeof( N2com1[a]);
    int Lb = sizeof( N2com2[a]);
    byte X = N2com1[a][0];
    byte Y = N2com2[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N2com1[a][b + 1];
    }
    N2com1[a][La - 1] = X;
    for (int b = 0; b < Lb - 1; b++)
    {
      Y ^= N2com2[a][b + 1];
    }
    N2com2[a][Lb - 1] = Y;
  }
}
void N2BCC3(byte N, byte N2, byte BH1) //PC号，探头号，编号
{
  N2com3[2] = N;
  N2com3[3] = N2;
  N2com3[5] = BH1;
  int La = 6;
  byte X = N2com3[0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N2com3[b + 1];
  }
  N2com3[La - 1] = X;
}
void N2BCC4(byte N, byte N2, byte LC1) //******量程1-6
{
  for (int a = 0; a < 5; a++)
  {
    N2com4[a][2] = N;
    N2com4[a][3] = N2;
    N2com4[a][5] = LC1;
    int La = sizeof(N2com4[a]);
    byte X = N2com4[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N2com4[a][b + 1];
    }
    N2com4[a][La - 1] = X;
  }
}
void N2BCC5(byte N, byte N2, byte N2SJ1, byte N2SJ2, byte N2SJ3, byte N2SJ4) //****** 4组数据0X00-FF
{
  for (int a = 0; a < 13; a++)
  {
    N2com5[a][2] = N;
    N2com5[a][3] = N2;
    N2com5[a][5] = N2SJ1;
    N2com5[a][6] = N2SJ2;
    N2com5[a][7] = N2SJ3;
    N2com5[a][8] = N2SJ4;
    int La = sizeof(N2com5[a]);
    byte X = N2com5[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N2com5[a][b + 1];
    }
    N2com5[a][La - 1] = X;
  }
}
void N2BCC6(byte N, byte N2, byte N2SJ5, byte N2SJ6, byte N2SJ7, byte N2SJ8) //****** 4组数据0X00-FF
{
  for (int a = 0; a < 4; a++)
  {
    N2com6[a][2] = N;
    N2com6[a][3] = N2;
    N2com6[a][6] = N2SJ5;
    N2com6[a][7] = N2SJ6;
    N2com6[a][8] = N2SJ7;
    N2com6[a][9] = N2SJ8;
    int La = sizeof(N2com6[a]);
    byte X = N2com6[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N2com6[a][b + 1];
    }
    N2com6[a][La - 1] = X;
  }
}
void N2BCC7(byte N, byte N2, byte N2SJ9, byte N2SJ10, byte N2SJ11, byte N2SJ12, byte N2SJ13) //****** 4组数据0X00-FF
{
  for (int a = 0; a < 4; a++)
  {
    N2com7[a][2] = N;
    N2com7[a][3] = N2;
    N2com7[a][5] = N2SJ9;
    N2com7[a][6] = N2SJ10;
    N2com7[a][7] = N2SJ11;
    N2com7[a][8] = N2SJ12;
    N2com7[a][9] = N2SJ13;
    int La = sizeof(N2com7[a]);
    byte X = N2com7[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N2com7[a][b + 1];
    }
    N2com7[a][La - 1] = X;
  }
}
void N2BCC8(byte N, byte N2, byte N2SJ14, byte N2SJ15, byte N2SJ16, byte N2SJ17, byte N2SJ18, byte N2SJ19, byte N2SJ20, byte N2SJ21, byte N2SJ22) //PC号，探头号，编号
{
  N2com8[2] = N;
  N2com8[3] = N2;
  N2com8[5] = N2SJ14;
  N2com8[6] = N2SJ15;
  N2com8[7] = N2SJ16;
  N2com8[8] = N2SJ17;
  N2com8[9] = N2SJ18;
  N2com8[10] = N2SJ19;
  N2com8[11] = N2SJ20;
  N2com8[12] = N2SJ21;
  N2com8[13] = N2SJ22;
  int La = 15;
  byte X = N2com8[0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N2com8[b + 1];
  }
  N2com8[La - 1] = X;
}


void N3BCC12(byte N, byte N3)           //经过BCC校验填补数组末尾校验位
{
  for (int a = 0; a < 13; a++)
  {
    N3com1[a][2] = N;
    N3com2[a][2] = N;
    N3com1[a][3] = N3;
    N3com2[a][3] = N3;
    int La = sizeof( N3com1[a]);
    int Lb = sizeof( N3com2[a]);
    byte X = N3com1[a][0];
    byte Y = N3com2[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N3com1[a][b + 1];
    }
    N3com1[a][La - 1] = X;
    for (int b = 0; b < Lb - 1; b++)
    {
      Y ^= N3com2[a][b + 1];
    }
    N3com2[a][Lb - 1] = Y;
  }
}
void N3BCC3(byte N, byte N3, byte BH1) //PC号，探头号，编号
{
  N3com3[2] = N;
  N3com3[3] = N3;
  N3com3[5] = BH1;
  int La = 6;
  byte X = N3com3[0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N3com3[b + 1];
  }
  N3com3[La - 1] = X;
}
void N3BCC4(byte N, byte N3, byte LC1) //******量程1-6
{
  for (int a = 0; a < 5; a++)
  {
    N3com4[a][2] = N;
    N3com4[a][3] = N3;
    N3com4[a][5] = LC1;
    int La = sizeof(N3com4[a]);
    byte X = N3com4[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N3com4[a][b + 1];
    }
    N3com4[a][La - 1] = X;
  }
}
void N3BCC5(byte N, byte N3, byte N3SJ1, byte N3SJ2, byte N3SJ3, byte N3SJ4) //****** 4组数据0X00-FF
{
  for (int a = 0; a < 13; a++)
  {
    N3com5[a][2] = N;
    N3com5[a][3] = N3;
    N3com5[a][5] = N3SJ1;
    N3com5[a][6] = N3SJ2;
    N3com5[a][7] = N3SJ3;
    N3com5[a][8] = N3SJ4;
    int La = sizeof(N3com5[a]);
    byte X = N3com5[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N3com5[a][b + 1];
    }
    N3com5[a][La - 1] = X;
  }
}
void N3BCC6(byte N, byte N3, byte N3SJ5, byte N3SJ6, byte N3SJ7, byte N3SJ8) //****** 4组数据0X00-FF
{
  for (int a = 0; a < 4; a++)
  {
    N3com6[a][2] = N;
    N3com6[a][3] = N3;
    N3com6[a][6] = N3SJ5;
    N3com6[a][7] = N3SJ6;
    N3com6[a][8] = N3SJ7;
    N3com6[a][9] = N3SJ8;
    int La = sizeof(N3com6[a]);
    byte X = N3com6[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N3com6[a][b + 1];
    }
    N3com6[a][La - 1] = X;
  }
}
void N3BCC7(byte N, byte N3, byte N3SJ9, byte N3SJ10, byte N3SJ11, byte N3SJ12, byte N3SJ13) //****** 4组数据0X00-FF
{
  for (int a = 0; a < 4; a++)
  {
    N3com7[a][2] = N;
    N3com7[a][3] = N3;
    N3com7[a][5] = N3SJ9;
    N3com7[a][6] = N3SJ10;
    N3com7[a][7] = N3SJ11;
    N3com7[a][8] = N3SJ12;
    N3com7[a][9] = N3SJ13;
    int La = sizeof(N3com7[a]);
    byte X = N3com7[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N3com7[a][b + 1];
    }
    N3com7[a][La - 1] = X;
  }
}
void N3BCC8(byte N, byte N3, byte N3SJ14, byte N3SJ15, byte N3SJ16, byte N3SJ17, byte N3SJ18, byte N3SJ19, byte N3SJ20, byte N3SJ21, byte N3SJ22) //PC号，探头号，编号
{
  N3com8[2] = N;
  N3com8[3] = N3;
  N3com8[5] = N3SJ14;
  N3com8[6] = N3SJ15;
  N3com8[7] = N3SJ16;
  N3com8[8] = N3SJ17;
  N3com8[9] = N3SJ18;
  N3com8[10] = N3SJ19;
  N3com8[11] = N3SJ20;
  N3com8[12] = N3SJ21;
  N3com8[13] = N3SJ22;
  int La = 15;
  byte X = N3com8[0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N3com8[b + 1];
  }
  N3com8[La - 1] = X;
}


void N4BCC12(byte N, byte N4)           //经过BCC校验填补数组末尾校验位
{
  for (int a = 0; a < 13; a++)
  {
    N4com1[a][2] = N;
    N4com2[a][2] = N;
    N4com1[a][3] = N4;
    N4com2[a][3] = N4;
    int La = sizeof( N4com1[a]);
    int Lb = sizeof( N4com2[a]);
    byte X = N4com1[a][0];
    byte Y = N4com2[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N4com1[a][b + 1];
    }
    N4com1[a][La - 1] = X;
    for (int b = 0; b < Lb - 1; b++)
    {
      Y ^= N4com2[a][b + 1];
    }
    N4com2[a][Lb - 1] = Y;
  }
}
void N4BCC3(byte N, byte N4, byte BH1) //PC号，探头号，编号
{
  N4com3[2] = N;
  N4com3[3] = N4;
  N4com3[5] = BH1;
  int La = 6;
  byte X = N4com3[0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N4com3[b + 1];
  }
  N4com3[La - 1] = X;
}
void N4BCC4(byte N, byte N4, byte LC1) //******量程1-6
{
  for (int a = 0; a < 5; a++)
  {
    N4com4[a][2] = N;
    N4com4[a][3] = N4;
    N4com4[a][5] = LC1;
    int La = sizeof(N4com4[a]);
    byte X = N4com4[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N4com4[a][b + 1];
    }
    N4com4[a][La - 1] = X;
  }
}
void N4BCC5(byte N, byte N4, byte N4SJ1, byte N4SJ2, byte N4SJ3, byte N4SJ4) //****** 4组数据0X00-FF
{
  for (int a = 0; a < 13; a++)
  {
    N4com5[a][2] = N;
    N4com5[a][3] = N4;
    N4com5[a][5] = N4SJ1;
    N4com5[a][6] = N4SJ2;
    N4com5[a][7] = N4SJ3;
    N4com5[a][8] = N4SJ4;
    int La = sizeof(N4com5[a]);
    byte X = N4com5[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N4com5[a][b + 1];
    }
    N4com5[a][La - 1] = X;
  }
}
void N4BCC6(byte N, byte N4, byte N4SJ5, byte N4SJ6, byte N4SJ7, byte N4SJ8) //****** 4组数据0X00-FF
{
  for (int a = 0; a < 4; a++)
  {
    N4com6[a][2] = N;
    N4com6[a][3] = N4;
    N4com6[a][6] = N4SJ5;
    N4com6[a][7] = N4SJ6;
    N4com6[a][8] = N4SJ7;
    N4com6[a][9] = N4SJ8;
    int La = sizeof(N4com6[a]);
    byte X = N4com6[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N4com6[a][b + 1];
    }
    N4com6[a][La - 1] = X;
  }
}
void N4BCC7(byte N, byte N4, byte N4SJ9, byte N4SJ10, byte N4SJ11, byte N4SJ12, byte N4SJ13) //****** 4组数据0X00-FF
{
  for (int a = 0; a < 4; a++)
  {
    N4com7[a][2] = N;
    N4com7[a][3] = N4;
    N4com7[a][5] = N4SJ9;
    N4com7[a][6] = N4SJ10;
    N4com7[a][7] = N4SJ11;
    N4com7[a][8] = N4SJ12;
    N4com7[a][9] = N4SJ13;
    int La = sizeof(N4com7[a]);
    byte X = N4com7[a][0];
    for (int b = 0; b < La - 1; b++)
    {
      X ^= N4com7[a][b + 1];
    }
    N4com7[a][La - 1] = X;
  }
}
void N4BCC8(byte N, byte N4, byte N4SJ14, byte N4SJ15, byte N4SJ16, byte N4SJ17, byte N4SJ18, byte N4SJ19, byte N4SJ20, byte N4SJ21, byte N4SJ22) //PC号，探头号，编号
{
  N4com8[2] = N;
  N4com8[3] = N4;
  N4com8[5] = N4SJ14;
  N4com8[6] = N4SJ15;
  N4com8[7] = N4SJ16;
  N4com8[8] = N4SJ17;
  N4com8[9] = N4SJ18;
  N4com8[10] = N4SJ19;
  N4com8[11] = N4SJ20;
  N4com8[12] = N4SJ21;
  N4com8[13] = N4SJ22;
  int La = 15;
  byte X = N4com8[0];
  for (int b = 0; b < La - 1; b++)
  {
    X ^= N4com8[b + 1];
  }
  N4com8[La - 1] = X;
}
