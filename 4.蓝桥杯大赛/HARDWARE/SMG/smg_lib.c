/********数码管显示*******/
#include "smg_lib.h"

uchar numChar[] = {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90}; 

void shumaguan(uchar wei, uchar num)
{
    select(7);  // 关闭数码管
    P0 = 0xff;
    select(0);

    P0 = 0x00;
    select(6);  // 位选
    P0 = 0x80 >> wei;   // [0x80]从左至右 [0x01] 从右至左
    select(0);

    P0 = 0xff;
    select(7);
    P0 = numChar[num];
    select(0);

    delayms(3);		// 延时 3ms
}
