void USERSET()            //     用户设置
{
  SwitchingSC(0X04);//显示用户模式图
  int k = USERCHOSE();     //******此函数中加入set键检测，按下set退回显示主页面
  delay(200);//***************kkkkk的值对应设置项图片***将k=i的值确定，切换到k值相应设置项目的 图片。
  switch (k) //相应的k值对应设置项里的操作《》
  {
    case 0:{}break;
    case 1: {
        SwitchingSC(0X00);//切换至此项画面
        //光标跟随    改SWITCH(); 为0-4  返回按键值
        switch (k)
        {
          case 1:
            break;
          case 2:
            break;
          case 3:
            break;
          case 4:
            break;
        }
      }
      break;
    case 2: {
        SwitchingSC(0X00);//切换至此项画面
        //光标跟随    改SWITCH(); 为0-4  返回按键值
        switch (k)
        {
          case 1:  //cps
            break;
          case 2:  //ugy
            break;
          case 3:  //usv
            break;
          case 4:  //
            break;
        }
      }
      break;
    case 3: {
        SwitchingSC(0X00); //切换至此项画面
        //光标跟随    改SWITCH(); 为0-4  返回按键值
        switch (k)
        {
          case 1:  //0.1~999999输入
            break;
          case 2:  //0.1~999999输入
            break;
          case 3:  //0.1~999999输入
            break;
          case 4:  //0.1~999999输入
            break;
        }
      }
      break;
    case 4: {}     break;

    case 5: {}     break;

    case 6: {}     break;

    case 7: {}     break;

    case 8: {}     break;

    case 9: {}     break;

    case 10: {}     break;

    case 11: {}     break;

    case 12: {}     break;

    case 13: {}     break;

    case 14: {}     break;

    case 15: {}     break;

    case 16: {}     break;

    case 17: {}     break;

    case 18: {}     break;

    case 19: {}     break;

    case 20: {}     break;
  }

}
int ADMINSET(void)           //    工厂设置
{
 int i=1;
 while(1)
 {
  SwitchingSC(0X04);//显示用户模式图
  int k = ADMINCHOSE(i);     //******此函数中加入set键检测，按下set退回显示主页面
  delay(200);
  //***************kkkkk的值对应设置项图片***将k=i的值确定，切换到k值相应设置项目的 图片。
  switch (k) //相应的k值对应设置项里的操作《》
  {
    case 0:{goto t;}break;
    case 1: {
       int in=1;
       while(1)
       {
        SwitchingSC(0X08);
        int m = NUMCHOSE(0X08,0X0E,0X06,0X0F,0X11,0X12,in);
        delay(200);
        switch (m)
        {
          case 0:{goto a1;}break;
          case 1: 
            {
              SwitchingSC(0X08);
              int N1num[3];
              blankR(0X08, 0X0D);
              blankR(0X08, 0X0C);
              upR(0X08, 0X09);
              N1num[0] = KEYIN(0X08, 0X16);
              delay(200);
              blankR(0X08, 0X09);
              blankR(0X08, 0X0D);
              upR(0X08, 0X0C);
              N1num[1] = KEYIN(0X08, 0X17);
              delay(200);
              blankR(0X08, 0X0C);
              blankR(0X08, 0X09);
              upR(0X08, 0X0D);
              N1num[2] = KEYIN(0X08, 0X18);
              delay(200);
       // N1=N1num[0]*100+N1num[1]*10+N1num[2];
              blankR(0X08, 0X0C);
              blankR(0X08, 0X09);
              blankR(0X08, 0X0D);
            }   break;
          case 2: {
              int N2num[3];
              blankR(0X08, 0X22);
              blankR(0X08, 0X13);
              upR(0X08, 0X10);
              N2num[0] = KEYIN(0X08, 0X19);
              delay(200);
              blankR(0X08, 0X10);
              blankR(0X08, 0X22);
              upR(0X08, 0X13);
              N2num[1] = KEYIN(0X08, 0X1A);
              delay(200);
              blankR(0X08, 0X13);
              blankR(0X08, 0X10);
              upR(0X08, 0X22);
              N2num[2] = KEYIN(0X08, 0X1B);
              delay(200);
       // N2=N2num[0]*100+N2num[1]*10+N2num[2];
              blankR(0X08, 0X13);
              blankR(0X08, 0X10);
              blankR(0X08, 0X22);
            }   break;
          case 3: {
              int N3num[3];
              blankR(0X08, 0X35);
              blankR(0X08, 0X34);
              upR(0X08, 0X33);
              N3num[0] = KEYIN(0X08, 0X26);
              delay(200);
              blankR(0X08, 0X33);
              blankR(0X08, 0X35);
              upR(0X08, 0X34);
              N3num[1] = KEYIN(0X08, 0X27);
              delay(200);
              blankR(0X08, 0X34);
              blankR(0X08, 0X33);
              upR(0X08, 0X35);
              N3num[2] = KEYIN(0X08, 0X28);
              delay(200);
          // N3=N3num[0]*100+N3num[1]*10+N3num[2];
              blankR(0X08, 0X34);
              blankR(0X08, 0X33);
              blankR(0X08, 0X35);
            }   break;
          case 4: {
              int N4num[3];
              blankR(0X08, 0X39);
              blankR(0X08, 0X38);
              upR(0X08, 0X36);
              N4num[0] = KEYIN(0X08, 0X2D);
              delay(200);
              blankR(0X08, 0X36);
              blankR(0X08, 0X39);
              upR(0X08, 0X38);
              N4num[1] = KEYIN(0X08, 0X2E);
              delay(200);
              blankR(0X08, 0X38);
              blankR(0X08, 0X36);
              upR(0X08, 0X39);
              N4num[2] = KEYIN(0X08, 0X2F);
              delay(200);
          // N4=N4num[0]*100+N4num[1]*10+N4num[2];
              blankR(0X08, 0X39); 
              blankR(0X08, 0X38);
              blankR(0X08, 0X36);
            }   break;
         case 5: {
              int N5num[3];
              blankR(0X08, 0X3C);
              blankR(0X08, 0X3B);
              upR(0X08, 0X3A);
              N5num[0] = KEYIN(0X08, 0X30);
              delay(200);
              blankR(0X08, 0X3A);
              blankR(0X08, 0X3C);
              upR(0X08, 0X3B);
              N5num[1] = KEYIN(0X08, 0X31);
              delay(200);
              blankR(0X08, 0X3A);
              blankR(0X08, 0X3B);
              upR(0X08, 0X3C);
              N5num[2] = KEYIN(0X08, 0X32);
              delay(200);
          // N=N5num[0]*100+N5num[1]*10+N5num[2];
              blankR(0X08, 0X3A);
              blankR(0X08, 0X3B);
              blankR(0X08, 0X3C);
            }   break;   
        }
        in=m;
        } 
     a1: ;
    }break;
    case 2: {
       int in=1;
       while(1)
       { 
        SwitchingSC(0X09); 
        int m = MENUCHOSE(0X09,0X19,0X1A,0X1B,0X27,in);
        delay(200);
        int ii=1;
        switch (m)
        {
          case 0:{goto a2;}break;
          case 1: {
     valuechose(0X09,0X26,"CPS","uSv/h","uGy/h","Rm");
     delay(200);
                  }   break;
          case 2: {
     valuechose(0X09,0X2D,"CPS","uSv/h","uGy/h","Rm");  
     delay(200);       
            }   break;
          case 3: {
     valuechose(0X09,0X30,"CPS","uSv/h","uGy/h","Rm");
     delay(200);
            }   break;
          case 4: {
     valuechose(0X09,0X31,"CPS","uSv/h","uGy/h","Rm"); 
     delay(200);        
            }   break;         
        }     
       in=m;
       }
    a2: ;
    }break;
    case 3: {}     break;

    case 4: {}    break;

    case 5: {}    break;

    case 6: {}    break;

    case 7: {}     break;

    case 8: {}     break;

    case 9: {}     break;

    case 10:  {}   break;

    case 11: {}    break;

    case 12:  {}   break;

    case 13:  {}   break;

    case 14: {}    break;

    case 15:  {}   break;

    case 16: {}     break;

    case 17: {}    break;

    case 18: {}    break;

    case 19: {}     break;
    
    case 20: {}     break;

    case 21: {}    break;

    case 22:  {}   break;

    case 23:  {}   break;

    case 24: {}    break;

    case 25:  {}   break;

    case 26: {}     break;

    case 27: {}    break;

    case 28: {}    break;

    case 29: {}     break;
    
    case 30: {}     break;
  }
  i=k;
 }
t:return (0);
}
