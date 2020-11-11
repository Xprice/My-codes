#include "../include/cloud.h"

//网络服务器模块


/*
函数名：network
函数功能：建立udp 并发服务器的服务端
函数的参数： 无
函数返回值：成功返回 0, 失败返回 -1 
*/
int network()
{
	//创建一个网络通道
	int iserver = socket( AF_INET, SOCK_STREAM, 0 );
	if ( -1 == iserver )
	{
		printf( "create socket fail\r\n" );
		return -1;
	}
	printf( "create socket success\r\n" );
	//绑定一个网络终端
	struct sockaddr_in stServer;
	stServer.sin_family = AF_INET;
	stServer.sin_port = htons(8888);
	stServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int ret = bind( iserver, (struct sockaddr *)&stServer, sizeof(struct sockaddr) );
	if ( -1 == ret )
	{
		printf( "bind fail\r\n" );
		return -1;
	}
	printf( "bind success\r\n" );
	
	//网络的监听
	ret = listen( iserver, 5 );
	if ( -1 == ret )
	{
		return -1;
	}
	printf( "listen success\r\n" );
	
	//接受客户端请求
	struct sockaddr_in stclient;
	//结构体的大小
	socklen_t len = sizeof( stclient );
	
	//创建一个文件描述副集合表
	fd_set stFdr;
	//初始化表 清空
	FD_ZERO( &stFdr );
	//将isever文件描述符添加到集合表中
	FD_SET(iserver,&stFdr);
	int Max=iserver;
	
	while (1)
	{
		//讲表中的数据复制给stFdrTmp	
		fd_set stFdrTmp = stFdr;
		/*监控ret 接受有数据位的个数
		  并将有数据位的bit位置为 1*/
		ret = select(Max+1,&stFdrTmp,NULL,NULL,NULL);
		if ( ret <= 0 )
		{
			printf("select error\r\n");
			continue;
		}
		printf("select ok,ret=%d\r\n",ret);
		
		int i = 0;
		for ( i = 0; i < Max+1; i++ )
		{
			if ( FD_ISSET(i,&stFdrTmp) )
			{
				if ( i == iserver )
				{
					//接受客户端的请求
					int iclient=accept(iserver,(struct sockaddr *)&stclient,&len);
					if ( -1 == iclient )
					{
						continue;
					}
					printf("iclient = %d\r\n", iclient);
					
					FD_SET(iclient,&stFdr);
					if ( Max < iclient )
					{
						Max = iclient;
					}
				}
				else
				{
					//登录模块
					enter( i );
					
					//选择功能模块
					char buf[SIZE] = {0};
					char arr[SIZE] = {0};
					
					do
					{
						//浏览当前路径文件
						memset(buf,0,SIZE);
						memset(arr,0,SIZE);
						strcpy(buf,".");
						lookDir( buf, arr );
						send(i,arr,SIZE,0);
											
						//接收需要操作的请求
						recv(i, buf, SIZE, 0);
						switch ( (int)buf[0] )
						{
							case 1:
									//浏览指定目录
									memset(buf,0,SIZE);
									memset(arr,0,SIZE);
									recv(i, buf, SIZE, 0);
									lookDir( buf, arr );
									send(i,arr,SIZE,0);
									break;
							case 2:
									//创建目录
									memset(buf,0,SIZE);
									recv(i, buf, SIZE, 0);
									creatDir( buf );
									break;
							case 3:
									//切换目录
									memset(buf,0,SIZE);
									recv(i, buf, SIZE, 0);
									cutDir( buf );
									break;
							case 4:
									//删除目录
									delDir( i );
									break;
							case 5:
									//上传文件
									upload( i );
									break;
							case 6:
									//下载文件
									download( i );
									break;
							case 7:
									//删除文件
									delFile( i );
									break;	
							default:
									break;
									
						}
					}while( 8 != (int)buf[0]);
					
					close(i);
					FD_CLR(i,&stFdr);
				}
			}
		}
	}
	return 0;
}
  

