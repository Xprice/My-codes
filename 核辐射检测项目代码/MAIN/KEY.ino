int in6NUM(char sid,char vid1,char vid2,char vid3,char vid4,char vid5,char vid6,char cid1,char cid2,char cid3,char cid4,char cid5,char cid6)
{
  blankR(sid, cid1);
  blankR(sid, cid2);
  blankR(sid, cid3);
  blankR(sid, cid4);
  blankR(sid, cid5);
  blankR(sid, cid6);
  SwitchingSC(sid);
  upR(sid,cid1);
  NUM[0]=KEYIN(sid,vid1);
  delay(200);
  blankR(sid, cid1);
  upR(sid,cid2);
  NUM[1]=KEYIN(sid,vid2);
  delay(200);
  blankR(sid, cid2);
  upR(sid,cid3);
  NUM[2]=KEYIN(sid,vid3);
  delay(200);
  blankR(sid, cid3);
  upR(sid,cid4);
  NUM[3]=KEYIN(sid,vid4);
  delay(200);
  blankR(sid, cid4);
  upR(sid,cid5);
  NUM[4]=KEYIN(sid,vid5);
  delay(200);
  blankR(sid, cid5);
  upR(sid,cid6);
  NUM[5]=KEYIN(sid,vid6);
  delay(200);
  blankR(sid, cid6);
  return (*NUM);
}
int valuechose(char sid, char cid,char q1[],char q2[],char q3[],char q4[]) //1-4选项
{ int i=0;
  while (1)
  {
    if (digitalRead(UP) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(UP) == LOW)
      {
        if (i < 4) {
          i++;
        }
        else {
          i = 1;
        }
        switch (i) //i值不同，填充不同的实心⚪
        {
          case 1: {
              upCH(sid,cid,q1);//显示单位一
            }
            break;
          case 2: {
              upCH(sid, cid,q2);//显示单位二
            }
            break;
          case 3: {
              upCH(sid, cid,q3);//显示单位三
            }
            break;
          case 4: {
              upCH(sid, cid,q4);//显示单位四
            }
            break;
        }
      }
      while (digitalRead(UP) == LOW);
    }

    if (digitalRead(DOWN) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(DOWN) == LOW)
      {
        if (i > 1) {
          i--;
        }
        else {
          i = 4;
        }
        switch (i) //i值不同，填充不同的实心⚪
        {
          case 1: {
              upCH(sid,cid,q1);//显示单位一
            }
            break;
          case 2: {
              upCH(sid, cid,q2);//显示单位二
            }
            break;
          case 3: {
              upCH(sid, cid,q3);//显示单位三
            }
            break;
          case 4: {
              upCH(sid, cid,q4);//显示单位四
            }
            break;
        }
        while (digitalRead(DOWN) == LOW);
      }
    }
    if (digitalRead(ENTER) == LOW) //检测到enter时，return 0
    {
      delay(50);
      if (digitalRead(ENTER) == LOW)
      {
        goto A;
      }
    }
  }
A: return (i);
}
/*密码输入*/
int KEYIN(char sid, char cid)   //0-9单位输入   a&b  is  key's  position.
{
  int i = 0;

  while (1)
  {
    if (digitalRead(UP) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(UP) == LOW)
      {
        if (i < 9) {
          i++;
        }
        else {
          i = 0;
        }
        upchar(sid, cid, i);
      }
      while (digitalRead(UP) == LOW);
    }

    if (digitalRead(DOWN) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(DOWN) == LOW)
      {
        if (i > 0) {
          i--;
        }
        else {
          i = 9;
        }
        upchar(sid, cid, i);
      }
      while (digitalRead(DOWN) == LOW);
    }
    if (digitalRead(ENTER) == LOW) //检测到enter时，return 0
    {
      delay(50);
      if (digitalRead(ENTER) == LOW)
      {
        goto A;
      }
    }
  }
A: return (i);
}
int NUMCHOSE(char sid, char cid1, char cid2, char cid3, char cid4, char cid5, int i) //1-5选项
{
  blankR(sid, cid1);
  blankR(sid, cid2);
  blankR(sid, cid3);
  blankR(sid, cid4);
  blankR(sid, cid5);
  switch (i)
  {
    case 1: upR(sid, cid1); break;
    case 2: upR(sid, cid2); break;
    case 3: upR(sid, cid3); break;
    case 4: upR(sid, cid4); break;
    case 5: upR(sid, cid5); break;
  }
  while (1)
  {
    if (digitalRead(SET) == LOW)
    {
      delay(50);
      if (digitalRead(SET) == LOW)
      {
        i = 0;
        goto A;
      }
    }
    if (digitalRead(DOWN) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(DOWN) == LOW)
      {
        if (i < 5) {
          i++;
        }
        else {
          i = 1;
        }
        switch (i) //i值不同，填充不同的实心⚪
        {
          case 1: {
              blankR(sid, cid5);
              blankR(sid, cid2);
              upR(sid, cid1);
            }
            break;
          case 2: {
              blankR(sid, cid1);
              blankR(sid, cid3);
              upR(sid, cid2);
            }
            break;
          case 3: {
              blankR(sid, cid2);
              blankR(sid, cid4);
              upR(sid, cid3);
            }
            break;
          case 4: {
              blankR(sid, cid3);
              blankR(sid, cid5);
              upR(sid, cid4);
            }
            break;
          case 5: {
              blankR(sid, cid4);
              blankR(sid, cid1);
              upR(sid, cid5);
            }
            break;
        }
      }
      while (digitalRead(DOWN) == LOW);
    }
    if (digitalRead(UP) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(UP) == LOW)
      {
        if (i > 1) {
          i--;
        }
        else {
          i = 5;
        }
        switch (i) //i值不同，填充不同的实心⚪
        {
          case 1: {
              blankR(sid, cid5);
              blankR(sid, cid2);
              upR(sid, cid1);
            }
            break;
          case 2: {
              blankR(sid, cid1);
              blankR(sid, cid3);
              upR(sid, cid2);
            }
            break;
          case 3: {
              blankR(sid, cid2);
              blankR(sid, cid4);
              upR(sid, cid3);
            }
            break;
          case 4: {
              blankR(sid, cid3);
              blankR(sid, cid5);
              upR(sid, cid4);
            }
            break;
          case 5: {
              blankR(sid, cid4);
              blankR(sid, cid1);
              upR(sid, cid5);
            }
            break;
        }
        while (digitalRead(UP) == LOW);
      }
    }
    if (digitalRead(ENTER) == LOW) //检测到enter时，return 0
    {
      delay(50);
      if (digitalRead(ENTER) == LOW)
      {
        goto A;
      }
    }
  }
A: return (i);
}
int MENUCHOSE(char sid, char cid1, char cid2, char cid3, char cid4, int i) //1-4选项
{
  blankR(sid, cid1);
  blankR(sid, cid2);
  blankR(sid, cid3);
  blankR(sid, cid4);
  switch (i)
  {
    case 1: upR(sid, cid1); break;
    case 2: upR(sid, cid2); break;
    case 3: upR(sid, cid3); break;
    case 4: upR(sid, cid4); break;
  }
  while (1)
  {
    if (digitalRead(SET) == LOW)
    {
      delay(50);
      if (digitalRead(SET) == LOW)
      {
        i = 0;
        goto A;
      }
    }
    if (digitalRead(DOWN) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(DOWN) == LOW)
      {
        if (i < 4) {
          i++;
        }
        else {
          i = 1;
        }
        switch (i) //i值不同，填充不同的实心⚪
        {
          case 1: {
              blankR(sid, cid4);
              blankR(sid, cid2);
              upR(sid, cid1);
            }
            break;
          case 2: {
              blankR(sid, cid1);
              blankR(sid, cid3);
              upR(sid, cid2);
            }
            break;
          case 3: {
              blankR(sid, cid2);
              blankR(sid, cid4);
              upR(sid, cid3);
            }
            break;
          case 4: {
              blankR(sid, cid3);
              blankR(sid, cid1);
              upR(sid, cid4);
            }
            break;
        }
      }
      while (digitalRead(DOWN) == LOW);
    }

    if (digitalRead(UP) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(UP) == LOW)
      {
        if (i > 1) {
          i--;
        }
        else {
          i = 4;
        }
        switch (i) //i值不同，填充不同的实心⚪
        {
          case 1: {
              blankR(sid, cid4);
              blankR(sid, cid2);
              upR(sid, cid1);
            }
            break;
          case 2: {
              blankR(sid, cid1);
              blankR(sid, cid3);
              upR(sid, cid2);
            }
            break;
          case 3: {
              blankR(sid, cid2);
              blankR(sid, cid4);
              upR(sid, cid3);
            }
            break;
          case 4: {
              blankR(sid, cid3);
              blankR(sid, cid1);
              upR(sid, cid4);
            }
            break;
        }
        while (digitalRead(UP) == LOW);
      }
    }
    if (digitalRead(ENTER) == LOW) //检测到enter时，return 0
    {
      delay(50);
      if (digitalRead(ENTER) == LOW)
      {
        goto A;
      }
    }
  }
A: return (i);
}
/*ADMINCHOSE*/
int ADMINCHOSE(int i)    //0-30单位输入******加入set键检测，按下set退回显示主页面
{
  blankR(0X04, 0X19);
  blankR(0X04, 0X1A);
  blankR(0X04, 0X1B);
  blankR(0X04, 0X27);
  blankR(0X04, 0X28);
  blankR(0X04, 0X29);
  blankR(0X04, 0X2C);
  blankR(0X04, 0X2E);
  blankR(0X04, 0X2F);
  blankR(0X04, 0X30);
  blankR(0X05, 0X19);
  blankR(0X05, 0X1A);
  blankR(0X05, 0X1B);
  blankR(0X05, 0X27);
  blankR(0X05, 0X28);
  blankR(0X05, 0X2E);
  blankR(0X05, 0X2F);
  blankR(0X05, 0X30);
  blankR(0X05, 0X31);
  blankR(0X05, 0X32);
  blankR(0X06, 0X21);
  blankR(0X06, 0X27);
  blankR(0X06, 0X28);
  blankR(0X06, 0X2A);
  blankR(0X06, 0X29);
  blankR(0X06, 0X2C);
  blankR(0X06, 0X2D);
  blankR(0X06, 0X2F);
  blankR(0X06, 0X30);
  blankR(0X06, 0X37);
  switch (i)
  {
    case 1: upR(0X04, 0X19); break;
    case 2: upR(0X04, 0X1A); break;
    case 3: upR(0X04, 0X1B); break;
    case 4: upR(0X04, 0X27); break;
    case 5: upR(0X04, 0X28); break;
    case 6: upR(0X04, 0X29); break;
    case 7: upR(0X04, 0X2C); break;
    case 8: upR(0X04, 0X2E); break;
    case 9: upR(0X04, 0X2F); break;
    case 10: upR(0X04, 0X30); break;
    case 11: upR(0X05, 0X19); break;
    case 12: upR(0X05, 0X1A); break;
    case 13: upR(0X05, 0X1B); break;
    case 14: upR(0X05, 0X27); break;
    case 15: upR(0X05, 0X28); break;
    case 16: upR(0X05, 0X2E); break;
    case 17: upR(0X05, 0X2F); break;
    case 18: upR(0X05, 0X30); break;
    case 19: upR(0X05, 0X31); break;
    case 20: upR(0X05, 0X32); break;
    case 21: upR(0X06, 0X21); break;
    case 22: upR(0X06, 0X27); break;
    case 23: upR(0X06, 0X28); break;
    case 24: upR(0X06, 0X2A); break;
    case 25: upR(0X06, 0X29); break;
    case 26: upR(0X06, 0X2C); break;
    case 27: upR(0X06, 0X2D); break;
    case 28: upR(0X06, 0X2F); break;
    case 29: upR(0X06, 0X30); break;
    case 30: upR(0X06, 0X37); break;
  }
  while (1)
  {
    if (digitalRead(SET) == LOW)
    {
      delay(50);
      if (digitalRead(SET) == LOW)
      {
        i = 0;
        goto B;
      }
    }
    if (digitalRead(DOWN) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(DOWN) == LOW)
      {
        if (i < 30) {
          i++;
        }
        else {
          i = 1;
        }
        switch (i) //i值不同，填充不同的实心⚪
        {
          case 1: SwitchingSC(0X04);
            blankR(0X06, 0X37);
            blankR(0X04, 0X1A);
            upR(0X04, 0X19);
            break;
          case 2: blankR(0X04, 0X19);
            blankR(0X04, 0X1B);
            upR(0X04, 0X1A);
            break;
          case 3: blankR(0X04, 0X1A);
            blankR(0X04, 0X27);
            upR(0X04, 0X1B);
            break;
          case 4: blankR(0X04, 0X1B);
            blankR(0X04, 0X28);
            upR(0X04, 0X27);
            break;
          case 5: blankR(0X04, 0X27);
            blankR(0X04, 0X29);
            upR(0X04, 0X28);
            break;
          case 6: blankR(0X04, 0X28);
            blankR(0X04, 0X2C);
            upR(0X04, 0X29);
            break;
          case 7:  blankR(0X04, 0X29);
            blankR(0X04, 0X2E);
            upR(0X04, 0X2C);
            break;
          case 8: blankR(0X04, 0X2C);
            blankR(0X04, 0X2F);
            upR(0X04, 0X2E);
            break;
          case 9: blankR(0X04, 0X2E);
            blankR(0X04, 0X30);
            upR(0X04, 0X2F);
            break;
          case 10: SwitchingSC(0X04);
            blankR(0X04, 0X2F);
            blankR(0X05, 0X19);
            upR(0X04, 0X30);
            break;
          case 11: SwitchingSC(0X05);
            blankR(0X04, 0X30);
            blankR(0X05, 0X1A);
            upR(0X05, 0X19);
            break;
          case 12: blankR(0X05, 0X19);
            blankR(0X05, 0X1B);
            upR(0X05, 0X1A);
            break;
          case 13:  blankR(0X05, 0X1A);
            blankR(0X05, 0X27);
            upR(0X05, 0X1B);
            break;
          case 14: blankR(0X05, 0X1B);
            blankR(0X05, 0X28);
            upR(0X05, 0X27);
            break;
          case 15: blankR(0X05, 0X27);
            blankR(0X05, 0X2E);
            upR(0X05, 0X28);
            break;
          case 16: blankR(0X05, 0X28);
            blankR(0X05, 0X2F);
            upR(0X05, 0X2E);
            break;
          case 17: blankR(0X05, 0X2E);
            blankR(0X05, 0X30);
            upR(0X05, 0X2F);
            break;
          case 18: blankR(0X05, 0X2F);
            blankR(0X05, 0X31);
            upR(0X05, 0X30);
            break;
          case 19: blankR(0X05, 0X30);
            blankR(0X05, 0X32);
            upR(0X05, 0X31);
            break;
          case 20: SwitchingSC(0X05);
            blankR(0X05, 0X31);
            blankR(0X06, 0X21);
            upR(0X05, 0X32);
            break;
          case 21: SwitchingSC(0X06);
            blankR(0X05, 0X32);
            blankR(0X06, 0X27);
            upR(0X06, 0X21);
            break;
          case 22: blankR(0X06, 0X21);
            blankR(0X06, 0X28);
            upR(0X06, 0X27);
            break;
          case 23:  blankR(0X06, 0X27);
            blankR(0X06, 0X2A);
            upR(0X06, 0X28);
            break;
          case 24: blankR(0X06, 0X28);
            blankR(0X06, 0X29);
            upR(0X06, 0X2A);
            break;
          case 25:  blankR(0X06, 0X2A);
            blankR(0X06, 0X2C);
            upR(0X06, 0X29);
            break;
          case 26: blankR(0X06, 0X29);
            blankR(0X06, 0X2D);
            upR(0X06, 0X2C);
            break;
          case 27: blankR(0X06, 0X2C);
            blankR(0X06, 0X2F);
            upR(0X06, 0X2D);
            break;
          case 28: blankR(0X06, 0X2D);
            blankR(0X06, 0X30);
            upR(0X06, 0X2F);
            break;
          case 29: blankR(0X06, 0X2F);
            blankR(0X06, 0X37);
            upR(0X06, 0X30);
            break;
          case 30: SwitchingSC(0X06);
            blankR(0X06, 0X30);
            blankR(0X04, 0X37);
            upR(0X06, 0X37);
            break;
          default:
            break;
        }
      }
      while (digitalRead(DOWN) == LOW);
    }
    if (digitalRead(UP) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(UP) == LOW)
      {
        if (i > 1) {
          i--;
        }
        else {
          i = 30;
        }
        switch (i) //i值不同，填充不同的实心⚪
        {
          case 1: SwitchingSC(0X04);
            blankR(0X06, 0X37);
            blankR(0X04, 0X1A);
            upR(0X04, 0X19);
            break;
          case 2: blankR(0X04, 0X19);
            blankR(0X04, 0X1B);
            upR(0X04, 0X1A);
            break;
          case 3: blankR(0X04, 0X1A);
            blankR(0X04, 0X27);
            upR(0X04, 0X1B);
            break;
          case 4: blankR(0X04, 0X1B);
            blankR(0X04, 0X28);
            upR(0X04, 0X27);
            break;
          case 5: blankR(0X04, 0X27);
            blankR(0X04, 0X29);
            upR(0X04, 0X28);
            break;
          case 6: blankR(0X04, 0X28);
            blankR(0X04, 0X2C);
            upR(0X04, 0X29);
            break;
          case 7:  blankR(0X04, 0X29);
            blankR(0X04, 0X2E);
            upR(0X04, 0X2C);
            break;
          case 8: blankR(0X04, 0X2C);
            blankR(0X04, 0X2F);
            upR(0X04, 0X2E);
            break;
          case 9: blankR(0X04, 0X2E);
            blankR(0X04, 0X30);
            upR(0X04, 0X2F);
            break;
          case 10: SwitchingSC(0X04);
            blankR(0X04, 0X2F);
            blankR(0X05, 0X19);
            upR(0X04, 0X30);
            break;
          case 11: SwitchingSC(0X05);
            blankR(0X04, 0X30);
            blankR(0X05, 0X1A);
            upR(0X05, 0X19);
            break;
          case 12: blankR(0X05, 0X19);
            blankR(0X05, 0X1B);
            upR(0X05, 0X1A);
            break;
          case 13:  blankR(0X05, 0X1A);
            blankR(0X05, 0X27);
            upR(0X05, 0X1B);
            break;
          case 14: blankR(0X05, 0X1B);
            blankR(0X05, 0X28);
            upR(0X05, 0X27);
            break;
          case 15: blankR(0X05, 0X27);
            blankR(0X05, 0X2E);
            upR(0X05, 0X28);
            break;
          case 16: blankR(0X05, 0X28);
            blankR(0X05, 0X2F);
            upR(0X05, 0X2E);
            break;
          case 17: blankR(0X05, 0X2E);
            blankR(0X05, 0X30);
            upR(0X05, 0X2F);
            break;
          case 18: blankR(0X05, 0X2F);
            blankR(0X05, 0X31);
            upR(0X05, 0X30);
            break;
          case 19: blankR(0X05, 0X30);
            blankR(0X05, 0X32);
            upR(0X05, 0X31);
            break;
          case 20: SwitchingSC(0X05);
            blankR(0X05, 0X31);
            blankR(0X06, 0X21);
            upR(0X05, 0X32);
            break;
          case 21: SwitchingSC(0X06);
            blankR(0X05, 0X32);
            blankR(0X06, 0X27);
            upR(0X06, 0X21);
            break;
          case 22: blankR(0X06, 0X21);
            blankR(0X06, 0X28);
            upR(0X06, 0X27);
            break;
          case 23:  blankR(0X06, 0X27);
            blankR(0X06, 0X2A);
            upR(0X06, 0X28);
            break;
          case 24: blankR(0X06, 0X28);
            blankR(0X06, 0X29);
            upR(0X06, 0X2A);
            break;
          case 25:  blankR(0X06, 0X2A);
            blankR(0X06, 0X2C);
            upR(0X06, 0X29);
            break;
          case 26: blankR(0X06, 0X29);
            blankR(0X06, 0X2D);
            upR(0X06, 0X2C);
            break;
          case 27: blankR(0X06, 0X2C);
            blankR(0X06, 0X2F);
            upR(0X06, 0X2D);
            break;
          case 28: blankR(0X06, 0X2D);
            blankR(0X06, 0X30);
            upR(0X06, 0X2F);
            break;
          case 29: blankR(0X06, 0X2F);
            blankR(0X06, 0X37);
            upR(0X06, 0X30);
            break;
          case 30: SwitchingSC(0X06);
            blankR(0X06, 0X30);
            blankR(0X04, 0X37);
            upR(0X06, 0X37);
            break;
          default:
            break;
        }
      }
      while (digitalRead(UP) == LOW);
    }
    if (digitalRead(ENTER) == LOW) //检测到enter时，return 0
    {
      delay(50);
      if (digitalRead(ENTER) == LOW)
      {
        goto B;
      }
    }
  }
B: return (i);
}
/*userchose*/
int USERCHOSE()    //0-20单位输入******加入set键检测，按下set退回显示主页面
{

  int i = 1;

  blankR(0X04, 0X19);
  blankR(0X04, 0X1A);
  blankR(0X04, 0X1B);
  blankR(0X04, 0X27);
  blankR(0X04, 0X28);
  blankR(0X04, 0X29);
  blankR(0X04, 0X2C);
  blankR(0X04, 0X2E);
  blankR(0X04, 0X2F);
  blankR(0X04, 0X30);
  blankR(0X05, 0X19);
  blankR(0X05, 0X1A);
  blankR(0X05, 0X1B);
  blankR(0X05, 0X27);
  blankR(0X05, 0X28);
  blankR(0X05, 0X2E);
  blankR(0X05, 0X2F);
  blankR(0X05, 0X30);
  blankR(0X05, 0X31);
  blankR(0X05, 0X32);
  blankR(0X06, 0X21);
  blankR(0X06, 0X27);
  blankR(0X06, 0X28);
  blankR(0X06, 0X2A);
  blankR(0X06, 0X29);
  blankR(0X06, 0X2C);
  blankR(0X06, 0X2D);
  blankR(0X06, 0X2F);
  blankR(0X06, 0X30);
  blankR(0X06, 0X37);

  upR(0X04, 0X19); //******************光标显示在1号选项
  while (1)
  {
    if (digitalRead(SET) == LOW)
    {
      delay(50);
      if (digitalRead(SET) == LOW)
      {
        i = 0;
        goto C;
      }
    }
    if (digitalRead(DOWN) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(DOWN) == LOW)
      {
        if (i < 20) {
          i++;
        }
        else {
          i = 1;
        }
        switch (i) //i值不同，填充不同的实心⚪
        {
          case 1: SwitchingSC(0X04);
            blankR(0X05, 0X32);
            blankR(0X04, 0X1A);
            upR(0X04, 0X19);
            break;
          case 2: blankR(0X04, 0X19);
            blankR(0X04, 0X1B);
            upR(0X04, 0X1A);
            break;
          case 3: blankR(0X04, 0X1A);
            blankR(0X04, 0X27);
            upR(0X04, 0X1B);
            break;
          case 4: blankR(0X04, 0X1B);
            blankR(0X04, 0X28);
            upR(0X04, 0X27);
            break;
          case 5: blankR(0X04, 0X27);
            blankR(0X04, 0X29);
            upR(0X04, 0X28);
            break;
          case 6: blankR(0X04, 0X28);
            blankR(0X04, 0X2C);
            upR(0X04, 0X29);
            break;
          case 7:  blankR(0X04, 0X29);
            blankR(0X04, 0X2E);
            upR(0X04, 0X2C);
            break;
          case 8: blankR(0X04, 0X2C);
            blankR(0X04, 0X2F);
            upR(0X04, 0X2E);
            break;
          case 9: blankR(0X04, 0X2E);
            blankR(0X04, 0X30);
            upR(0X04, 0X2F);
            break;
          case 10: SwitchingSC(0X04);
            blankR(0X04, 0X2F);
            blankR(0X05, 0X19);
            upR(0X04, 0X30);
            break;
          case 11: SwitchingSC(0X05);
            blankR(0X04, 0X30);
            blankR(0X05, 0X1A);
            upR(0X05, 0X19);
            break;
          case 12: blankR(0X05, 0X19);
            blankR(0X05, 0X1B);
            upR(0X05, 0X1A);
            break;
          case 13:  blankR(0X05, 0X1A);
            blankR(0X05, 0X27);
            upR(0X05, 0X1B);
            break;
          case 14: blankR(0X05, 0X1B);
            blankR(0X05, 0X28);
            upR(0X05, 0X27);
            break;
          case 15: blankR(0X05, 0X27);
            blankR(0X05, 0X2E);
            upR(0X05, 0X28);
            break;
          case 16: blankR(0X05, 0X28);
            blankR(0X05, 0X2F);
            upR(0X05, 0X2E);
            break;
          case 17: blankR(0X05, 0X2E);
            blankR(0X05, 0X30);
            upR(0X05, 0X2F);
            break;
          case 18: blankR(0X05, 0X2F);
            blankR(0X05, 0X31);
            upR(0X05, 0X30);
            break;
          case 19: blankR(0X05, 0X30);
            blankR(0X05, 0X32);
            upR(0X05, 0X31);
            break;
          case 20: SwitchingSC(0X05);
            blankR(0X05, 0X31);
            blankR(0X04, 0X19);
            upR(0X05, 0X32);
            break;

          default:
            break;
        }
      }
      while (digitalRead(DOWN) == LOW);
    }
    if (digitalRead(UP) == LOW)
    {
      delay(50);   //延时消抖
      if (digitalRead(UP) == LOW)
      {
        if (i > 1) {
          i--;
        }
        else {
          i = 20;
        }
        switch (i) //i值不同，填充不同的实心⚪
        {
          case 1: SwitchingSC(0X04);
            blankR(0X05, 0X32);
            blankR(0X04, 0X1A);
            upR(0X04, 0X19);
            break;
          case 2: blankR(0X04, 0X19);
            blankR(0X04, 0X1B);
            upR(0X04, 0X1A);
            break;
          case 3: blankR(0X04, 0X1A);
            blankR(0X04, 0X27);
            upR(0X04, 0X1B);
            break;
          case 4: blankR(0X04, 0X1B);
            blankR(0X04, 0X28);
            upR(0X04, 0X27);
            break;
          case 5: blankR(0X04, 0X27);
            blankR(0X04, 0X29);
            upR(0X04, 0X28);
            break;
          case 6: blankR(0X04, 0X28);
            blankR(0X04, 0X2C);
            upR(0X04, 0X29);
            break;
          case 7:  blankR(0X04, 0X29);
            blankR(0X04, 0X2E);
            upR(0X04, 0X2C);
            break;
          case 8: blankR(0X04, 0X2C);
            blankR(0X04, 0X2F);
            upR(0X04, 0X2E);
            break;
          case 9: blankR(0X04, 0X2E);
            blankR(0X04, 0X30);
            upR(0X04, 0X2F);
            break;
          case 10: SwitchingSC(0X04);
            blankR(0X04, 0X2F);
            blankR(0X05, 0X19);
            upR(0X04, 0X30);
            break;
          case 11: SwitchingSC(0X05);
            blankR(0X04, 0X30);
            blankR(0X05, 0X1A);
            upR(0X05, 0X19);
            break;
          case 12: blankR(0X05, 0X19);
            blankR(0X05, 0X1B);
            upR(0X05, 0X1A);
            break;
          case 13:  blankR(0X05, 0X1A);
            blankR(0X05, 0X27);
            upR(0X05, 0X1B);
            break;
          case 14: blankR(0X05, 0X1B);
            blankR(0X05, 0X28);
            upR(0X05, 0X27);
            break;
          case 15: blankR(0X05, 0X27);
            blankR(0X05, 0X2E);
            upR(0X05, 0X28);
            break;
          case 16: blankR(0X05, 0X28);
            blankR(0X05, 0X2F);
            upR(0X05, 0X2E);
            break;
          case 17: blankR(0X05, 0X2E);
            blankR(0X05, 0X30);
            upR(0X05, 0X2F);
            break;
          case 18: blankR(0X05, 0X2F);
            blankR(0X05, 0X31);
            upR(0X05, 0X30);
            break;
          case 19: blankR(0X05, 0X30);
            blankR(0X05, 0X32);
            upR(0X05, 0X31);
            break;
          case 20: SwitchingSC(0X05);
            blankR(0X05, 0X31);
            blankR(0X04, 0X19);
            upR(0X05, 0X32);
            break;

          default:
            break;
        }
      }
      while (digitalRead(UP) == LOW);
    }
    if (digitalRead(ENTER) == LOW) //检测到enter时，return 0
    {
      delay(50);
      if (digitalRead(ENTER) == LOW)
      {
        goto C;
      }
    }
  }
C: return (i);
}
