#ifndef _CLOUD_H_
#define _CLOUD_H_

#include <stdio.h>
//网络模块
#include <sys/types.h>        
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>

//下载
#include <fcntl.h>

#include <unistd.h>

#define SIZE 100


//密码登录
#include <stdlib.h>

enum judge
{
	ERROR = -1,
	OK,
};

//类型定义
struct password 
{
	char name [SIZE];
	long int pass;
	long int guard;
};
typedef struct password dataType;

//定义一个结构体
typedef struct list
{
	dataType data;
	struct list *pNext;
}LIST;

LIST lis;




/*
函数名：network
函数功能：建立udp 并发服务器的客户端
函数的参数： 无
函数返回值：成功返回 0, 失败返回 -1 
*/
int network();


/*
函数名：menu
函数功能：显示菜单
函数参数：无
返回值：无
*/
void menu();


/*
函数名：enter
函数功能：实现账户的安全登录
函数的参数：int iclient 文件描述符
返回值：成功返回 0 失败 -1
*/
int enter( char *str );


/*
函数名：lookDir
函数功能：浏览指定目录信息
函数的参数：int iclient 文件描述符
函数返回值：无
*/
void lookDir( int iclient );


/*
函数名：creatDir
函数功能：创建目录
函数的参数：int iclient 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int creatDir( int iclient );


/*
函数名：cutDir
函数功能：切换目录
函数的参数：int iclient 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int cutDir( int iclient );


/*
函数名：delDir
函数功能：删除目录
函数的参数：int iclient 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int delDir( int iclient );


/*
函数名：download
函数功能：下载文件
函数参数：int iclient 文件描述符
函数返回值: 无
*/
void download( int iclient );


/*
函数名：upload
函数功能：上传文件
函数参数：int iclient 文件描述符
函数返回值：
*/

void upload( int iclient );


/*
函数名：delFile
函数功能：删除文件
函数的参数：int iclient 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int delFile(  int iclient );




/*
密码登录模块
*/

//登录密码菜单
void m_enu();


//登录账户
int passEnter( LIST * pList,char *arr );


//找回密码
int findPass( LIST * pList );


//申请账户
int applyFor( LIST * pList );


//创建一个结点
LIST * creation ( );

//保存数据
void saveData ( LIST *pList );

//读取数据
void readData ( LIST *pList );






#endif //_CLOUD_H_