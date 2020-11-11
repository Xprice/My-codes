#include "../include/cloud.h"

//目录的操作模块

/*
函数名：lookDir
函数功能：浏览目录
函数参数一：char *buf 浏览的目录名
		二：char *arr 用于发送的目录信息
返回值：成功返回 0， 失败 -1
*/
int lookDir( char *buf, char *arr )
{
	//打开目录
	DIR *dir = opendir( buf );
	if ( NULL == dir )
	{
		printf("opendir error\r\n");
		return -1;
	}
	//定义一个结构体变量保存目录属性
	struct dirent *stdinfo;
	int tmp = 0;
	while (1)
	{
		if ( (stdinfo=readdir(dir)) == 0 )
		{
			break;
		}
		strcat( arr,stdinfo->d_name );
		strcat(arr, "   ");
		
		//换行
		tmp++;
		if ( 0 == tmp%6 )
		{
			strcat(arr, "\n");
		}
	}
	closedir(dir);
	return 0;
}


/*
函数名：creatDir
函数功能：创建目录
函数的参数：char *buf 存放目录名的地址
返回值：成功返回 0， 失败返回 -1
*/
int creatDir( char *buf )
{
	char arr[SIZE] = {0};
	char *p = NULL;
	//获取当前路径
	p = getcwd( arr, SIZE );
	if ( NULL == p )
	{
		printf("the SIZE to small\r\n");
		return -1;
	}
	strcat( arr, "/" );
	strcat( arr, buf );
	mkdir( arr, 00755 );
	
	return 0;
}


/*
函数名：cutDir
函数功能：切换目录
函数的参数：char *buf 存放目录名的地址
返回值：成功返回 0， 失败返回 -1
*/
int cutDir( char *buf )
{
	char arr[SIZE] = {0};
	char *p = NULL;
	//获取当前路径
	p = getcwd( arr, SIZE );
	if ( NULL == p )
	{
		printf("the SIZE to small\r\n");
		return -1;
	}
	strcat( arr, "/" );
	strcat( arr, buf );
	chdir( arr );
	
	return 0;	
}


/*
函数名：delDir
函数功能：删除目录
函数的参数： int i 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int delDir(  int i )
{
	char buf[SIZE] = {0};
	recv(i, buf, SIZE, 0);
	char arr[SIZE] = {0};
	char *p = NULL;
	//获取当前路径
	p = getcwd( arr, SIZE );
	if ( NULL == p )
	{
		printf("the SIZE to small\r\n");
		return -1;
	}
	strcat( arr, "/" );
	strcat( arr, buf );
	rmdir( arr );
	
	return 0;
}


/*
函数名：download
函数功能：下载文件
函数参数： int i 文件描述符
函数返回值：无
*/
void download( int i )
{
	char buf[SIZE] = {0};
	recv( i, buf, SIZE, 0 );
	
	//打开需要下载的文件
	int fd = open( buf, O_RDONLY );
	if ( -1 == fd )
	{
		printf( "open file err\r\n" );
		return ;
	}
	
	//获取文件属性
	struct stat file;
	stat( buf, &file );
	
	//文件的大小
	memset( buf, 0, SIZE );
	buf[0] = (char)file.st_size;
	send( i, buf, 1, 0 );
	printf( "file size send success\r\n" );
	
	//获取文件内容
	memset( buf, 0, SIZE );
	while ( read(fd,buf,SIZE) > 0 )
	{
		send( i, buf, strlen(buf), 0 );
		memset( buf, 0, SIZE );
	}
	printf( "file send success\r\n" );
	
}

/*
函数名：upload
函数功能：上传文件
函数参数：int i 文件描述符
函数返回值：无
*/

void upload( int i )
{
	char buf[SIZE] = {0};
	//文件名
	recv(i, buf, SIZE, 0);
	int fd = open( buf, O_WRONLY | O_CREAT, 0777 );
	if ( -1 == fd )
	{
		printf("open file err\r\n");
		return ;
	}
	memset(buf, 0, SIZE);	
	
	while ( ( recv(i, buf, SIZE, 0) ) > 0 )
	{
		write(fd, buf, strlen(buf));
		memset(buf, 0, SIZE);	
	}
	
}

/*
函数名：delFile
函数功能：删除文件
函数的参数： int i 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int delFile( int i )
{
	char buf[SIZE] = {0};
	recv(i, buf, SIZE, 0);
	char arr[SIZE] = {0};
	char *p = NULL;
	//获取当前路径
	p = getcwd( arr, SIZE );
	if ( NULL == p )
	{
		printf("the SIZE to small\r\n");
		return -1;
	}
	strcat( arr, "/" );
	strcat( arr, buf );
	remove( arr );
	
	return 0;
}

