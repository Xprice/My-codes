/************矩阵键盘扫描**** 返回按键值，如无按键按下则返回 0****/
// 矩阵键盘
// IAP15 芯片的 WR/RD 功能不是 P36/P37 引脚功能，故用 P42/P44 引脚代替
// 即：P3^6 => P42  P3^7 => P44
#include "Keypad_lib.h"

uchar keyScan()
{
	uchar keyValue = 0;
  // 键盘初始化
  P3 = 0x0f; P42 = 0; P44 = 0;
  // 键盘扫描
  if (P3 != 0x0f)
  {
      delayms(10);    // 消抖
      if (P3 != 0x0f)
      {
          switch (P3)
          {
                case 0x07: keyValue = 13;break;
                case 0x0b: keyValue = 9; break;
                case 0x0d: keyValue = 5; break;
                case 0x0e: keyValue = 1; break;
                default: return 0;
          }
            // 键盘翻转
          P3 = 0xf0; P42 = 1; P44 = 1;
          // 扫描
          if (!P34) keyValue += 3;
          else if (!P35) keyValue += 2;
          else if (!P42) keyValue += 1;
          else if (!P44) keyValue += 0;
          else return 0;
          // 等待按键抬起
          while (P3 != 0xf0);
          while (!P42);
          while (!P44);
      }
  }
  return keyValue;	// 返回按键值，如无按键按下则返回 0
}