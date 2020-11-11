/**********外部中断初始化**********/
/*INT0*/

#include "INTinit_lib.h"
void initInter0()
{
	IT0 = 1;	// 中断触发方式：[0]低电平触发 [1]下沿触发
	EX0 = 1;	// 打开外部中断
	EA = 1; 	// 开启总中断
}
/*INT1*/
void initInter1()
{
	IT1 = 1;	// 中断触发方式：[0]低电平触发 [1]下沿触发
	EX1 = 1;	// 打开外部中断
	EA = 1; 	// 开启总中断
}

#endif