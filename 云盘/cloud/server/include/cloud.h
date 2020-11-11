#ifndef _CLOUD_H_
#define _CLOUD_H_

#include <stdio.h>
//网络模块
#include <sys/types.h>        
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

//目录操作
#include <dirent.h>

//下载
#include <sys/stat.h>
#include <fcntl.h>



#define SIZE 100


/*
函数名：network
函数功能：建立udp 并发服务器的服务端
函数的参数： 无
函数返回值：成功返回 0, 失败返回 -1 
*/
int network();

/*
函数名：lookDir
函数功能：浏览目录
函数参数一：char *buf 浏览的目录名
		二：char *arr 用于发送的目录信息
返回值：成功返回 0， 失败 -1
*/
int lookDir( char *buf, char *arr );



/*
函数名：creatDir
函数功能：创建目录
函数的参数：char *buf 存放目录名的地址
返回值：成功返回 0， 失败返回 -1
*/
int creatDir( char *buf );


/*
函数名：cutDir
函数功能：切换目录
函数的参数：char *buf 存放目录名的地址
返回值：成功返回 0， 失败返回 -1
*/
int cutDir( char *buf );



/*
函数名：delDir
函数功能：删除目录
函数的参数：char *buf 目录名
返回值：成功返回 0， 失败返回 -1
*/
int delDir( int i );


/*
函数名：enter
函数功能：实现账户的安全登录
函数的参数：int i 文件描述符 
返回值：成功返回 0 失败 -1
*/
int enter( int i  );


/*
函数名：download
函数功能：下载文件
函数参数： int i 文件描述符
函数返回值：无
*/
void download( int i );



/*
函数名：upload
函数功能：上传文件
函数参数：int i 文件描述符
函数返回值：无
*/

void upload( int i );

/*
函数名：delFile
函数功能：删除文件
函数的参数： int i 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int delFile( int i );



#endif //_CLOUD_H_


