#include "../include/cloud.h"

//目录的操作模块

/*
函数名：menu
函数功能：显示菜单
函数参数：无
返回值：无
*/
void menu()
{
	printf("==================================\r\n");
	printf("         *欢迎登陆云端*\r\n");
	printf("    1---------------浏览目录\r\n");
	printf("    2---------------创建目录\r\n");
	printf("    3---------------切换目录\r\n");
	printf("    4---------------删除目录\r\n");
	printf("    5---------------上传文件\r\n");
	printf("    6---------------下载文件\r\n");
	printf("    7---------------删除文件\r\n");
	printf("    8---------------退出系统\r\n");
	printf("==================================\r\n");
	
}


/*
函数名：lookDir
函数功能：浏览指定目录信息
函数的参数：int iclient 文件描述符
函数返回值：无
*/
void lookDir( int iclient )
{
	char buf[SIZE] = {0};
	//输入目录名
	printf("请输入需要查找的目录名\r\n");
	strcat(buf,"./");
	scanf("%s", buf);
	//发送目录名给服务器
	send( iclient, buf, SIZE, 0 );

	//接收目录信息
	memset(buf, 0, SIZE);
	recv(iclient, buf, SIZE, 0);

	if ( strlen(buf) > 0 )
	{
		printf("文件系统目录\r\n");
		printf("%s\r\n", buf);
		return;
	}
	printf("您输入的目录不存在\r\n");
}


/*
函数名：creatDir
函数功能：创建目录
函数的参数：int iclient 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int creatDir( int iclient )
{
	char buf[SIZE] = {0};
	//输入目录名
	printf("请输入需要创建的目录名\r\n");
	scanf("%s", buf);
	//发送目录名给服务器
	send( iclient, buf, SIZE, 0 );
	
	printf("创建成功\r\n");
	return 0;
}


/*
函数名：cutDir
函数功能：切换目录
函数的参数：int iclient 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int cutDir( int iclient )
{
	char buf[SIZE] = {0};
	//输入目录名
	printf("请输入需要切换的目录名\r\n");
	scanf("%s", buf);
	//发送目录名给服务器
	send( iclient, buf, SIZE, 0 );

	printf("切换目录成功\r\n");
	
	return 0;

}


/*
函数名：delDir
函数功能：删除目录
函数的参数：int iclient 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int delDir( int iclient )
{
	char buf[SIZE] = {0};
	//输入目录名
	printf("请输入需要删除的目录名\r\n");
	scanf("%s", buf);
	//发送目录名给服务器
	send( iclient, buf, SIZE, 0 );

	printf("删除目录成功\r\n");
	
	return 0;

}



/*
函数名：download
函数功能：下载文件
函数参数：int iclient 文件描述符
函数返回值: 无
*/
void download( int iclient )
{
	char buf[SIZE] = {0};
	//输入需要下载的文件
	printf("请输入需要下载的文件名\r\n");
	scanf("%s", buf);
	
	//发送文件名给服务器
	send( iclient, buf, SIZE, 0 );
	//接收文件的大小属性
	int ret = recv( iclient, buf, 1, 0 );
	int file_size = (int)buf[0];
	if ( -1 == ret )
	{
		printf( "recv data fail\r\n" );
	}
	//打印下载文件的大小
	printf( "download file_size = %d\r\n", file_size );
	
	//输入需要需要保存的文件名
	memset( buf, 0, SIZE );
	printf("输入需要需要保存的文件名\r\n");
	scanf("%s", buf);
	
	//下载内容
	int fd = open( buf, O_WRONLY | O_CREAT, 0777 );
	if ( -1 == fd )
	{
		printf( "open file err\r\n" );
		return ;
	}
	memset( buf, 0, SIZE );
	int tmp = 0;
	int rSize = 0;
	while (tmp != file_size)
	{
		rSize = recv(iclient, buf, SIZE, 0);
		write( fd, buf, strlen(buf) );
		//计算文件的大小
		tmp += rSize;
		memset( buf, 0, SIZE );	
	}
	printf( "file download success\r\n" );
}


/*
函数名：upload
函数功能：上传文件
函数参数：int iclient 文件描述符
函数返回值：
*/

void upload( int iclient )
{
	char buf[SIZE] = {0};
	//输入需要上传的文件名
	printf("请输入需要上传的文件名\r\n");
	scanf("%s", buf);
	//先上传文件名
	send(iclient, buf, SIZE ,0);
	
	int fd = open( buf, O_RDONLY );
	if ( -1 == fd )
	{
		printf( "open file err\r\n" );
		return ;
	}
	//获取文件内容
	memset( buf, 0, SIZE );
	while ( read(fd,buf,SIZE) > 0 )
	{
		send( iclient, buf, strlen(buf), 0 );
		memset( buf, 0, SIZE );
	}
	printf( "file upload success\r\n" );

}


/*
函数名：delFile
函数功能：删除文件
函数的参数：int iclient 文件描述符
返回值：成功返回 0， 失败返回 -1
*/
int delFile( int iclient )
{
	char buf[SIZE] = {0};
	//输入目录名
	printf("请输入需要删除的文件名\r\n");
	scanf("%s", buf);
	//发送目录名给服务器
	send( iclient, buf, SIZE, 0 );

	printf("删除文件成功\r\n");
	
	return 0;

}
