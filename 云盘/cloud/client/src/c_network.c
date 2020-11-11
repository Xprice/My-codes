#include "../include/cloud.h"

//网络服务器模块


/*
函数名：network
函数功能：建立udp 并发服务器的客户端
函数的参数： 无
函数返回值：成功返回 0, 失败返回 -1 
*/
int network()
{
	//创建一个网络通道
	int iclient = socket( AF_INET, SOCK_STREAM, 0 );
	if ( -1 == iclient )
	{
		printf( "create socket fail\r\n" );
		return -1;
	}
	printf( "create socket success\r\n" );
	
	struct sockaddr_in stServer;
	stServer.sin_family = AF_INET;
	stServer.sin_port = htons(8888);
	stServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	//建立连接
	int ret = connect( iclient, (struct sockaddr *)&stServer, sizeof(struct sockaddr) );
	if ( -1 == ret )
	{
		printf( "connect fail\r\n" );
		return -1;
	}
	printf( "connect success\r\n" );
		
	//登录模块
	char buf[SIZE] = {0};
	enter( buf );
	if ( 0 == strlen(buf))
	{
		return -1;
	}
	//发送用户名给服务器
	send( iclient,buf,SIZE,0 );
	//显示目录
	recv(iclient, buf, SIZE, 0);
	printf("您当前的文件目录\r\n");
	printf("%s\r\n",buf);
	
	
	//选择功能模块
	int arr[SIZE] = {0};
	while (1)
	{	
		//菜单显示模块
		menu();
		
		//显示当前文件目录
		memset(buf,0,SIZE);
		recv(iclient, buf, SIZE, 0);
		printf("%s\r\n",buf);
		
		printf("请输入需要操作的序号\r\n");
		scanf("%d",&arr[0] );
		getchar();
		
		//发送操作序号给服务器
		send( iclient, arr, 1, 0 );
		
		switch ( arr[0] )
		{
			case 1:
					//浏览指定目录
					lookDir( iclient );
					break;
			case 2:
					//创建目录
					creatDir( iclient );
					break;
			case 3:
					//切换目录
					cutDir( iclient );
					break;
			case 4:
					//删除目录
					delDir( iclient );
					break;
			case 5:
					//上传文件
					upload( iclient );
					break;
			case 6:
					//下载文件
					download( iclient );
					break;
			case 7:
					//删除文件
					delFile(  iclient );
					break;
			case 8:
					//退出系统
					printf("谢谢使用，祝您生活愉快\r\n");
					close( iclient );
					return 0;
			default :
					//提示
					printf("输入有误，请重新输入\r\n");
					break;
		}
	}	
}
