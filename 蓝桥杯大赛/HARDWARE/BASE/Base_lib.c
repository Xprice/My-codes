/*************上电初始化*************/
#include "Base_lib.h"

void select(uchar num)
{
	switch (num)
	{
    	case 4: P2 = (P2 & 0x1f) | 0x80; break;//led
    	case 5: P2 = (P2 & 0x1f) | 0xa0; break;//buzz
    	case 6: P2 = (P2 & 0x1f) | 0xc0; break;//SMG（Y6C位选）
    	case 7: P2 = (P2 & 0x1f) | 0xe0; break;//SMG（Y7C段选）
    	default: P2 &= 0x1f; break;            //锁存
	}
}
void init()
{
	// 关闭蜂鸣器、LED灯、数码管
	select(4);  // 选择LED灯
	P0 = 0xff;  //关闭led
	select(5);  // 选择蜂鸣器
	P0 = 0x00;   //关闭buzz
	select(6);  // Y6C（位选）  选中全部数码管
	P0 = 0xff;  
	select(7);  // Y7C（段码） 关闭数码管
	P0 = 0xff;
	
	select(0);  // 锁存
}

