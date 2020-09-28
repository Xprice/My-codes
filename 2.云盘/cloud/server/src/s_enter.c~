#include "../include/cloud.h"


/*
密码登录模块
*/


/*
函数名：enter
函数功能：实现账户的安全登录
函数的参数：int i 文件描述符 
返回值：成功返回 0 失败 -1
*/
int enter( int i  )
{	
	char buf[SIZE] = {0};
	char arr[SIZE] = {0};
	//接收登录请求
	
	int ret = recv(i, buf, SIZE, 0);
	if ( ret <= 0 )
	{
		printf("recv error\r\n");
	}
	
	strcat(arr,"../data/");
	strcat(arr,buf);
	memset(buf,0,SIZE);

	//获取当前用户名下文件名保存到arr
	if ( ret = lookDir( arr, buf ) == 0 )
	{
		//发送当前路径目录中所有文件名
		send(i, buf, SIZE, 0);
		printf("send lookDir ok\r\n");
		//切换到此文件目录
		cutDir( arr );
		return 0;
	}
	//创建目录
	creatDir( arr );
	cutDir( arr );
	
	memset(arr,0,SIZE);
	strcpy(arr,"no file");
	send(i,arr,SIZE,0);
		
	return -1;
}
