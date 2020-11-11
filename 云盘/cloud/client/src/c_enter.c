#include "../include/cloud.h"

/*
密码登录模块
*/


/*
函数名：enter
函数功能：实现账户的安全登录
函数的参数：无
返回值：成功返回用户名 失败 -1
*/
int enter( char *str )
{
	//定义指针变量
	LIST *pList = NULL;
	pList = creation ( );
	
	//读取结点数据
	readData ( pList );
	
	char buf[SIZE] = {0};
	int tmp = 0;
	
	while (1)
	{
		//菜单
		m_enu();
		scanf("%d",&tmp);
		getchar();
		
		switch ( tmp )
		{
			case 1:
					//登录账户
					passEnter( pList ,buf);
					if ( 0 != strlen(buf) )
					{
						strcpy(str,buf);
						saveData ( pList );
						return OK;
					}
					break;
			case 2:
					//申请账户
					applyFor( pList );
					break;
			case 3:
					//找回密码
					findPass( pList );
					break;
			case 4:
					//退出系统
					saveData ( pList );
					printf("谢谢使用\r\n");
					return ;
			default:
				printf("您输入有误请重新输入\r\n");
				break;
		}
	}	
}



//菜单
void m_enu()
{
	printf("===========================================\r\n");
	printf("             欢迎进入云端\r\n");
	printf("      1---------------------登录账户\r\n");
	printf("      2---------------------申请账户\r\n");
	printf("      3---------------------找回密码\r\n");
	printf("      4---------------------退出系统\r\n");
	printf("===========================================\r\n");
}


//登录账户
int passEnter( LIST * pList, char *arr )
{	
	//判断链表是否存在
	if ( NULL == pList )
	{
		return ERROR;
	}
	
	long int p_ass = 0;
	//输入用户名比对
	char buf[SIZE] = {0};
	printf("请输入用户名\r\n");
	scanf("%s",buf);
	
	//定义指针变量
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		//查找用户名存在
		if ( 0 == strcmp ( p->data.name, buf ) )
		{
			//输入密码判断
			printf("请输入密码\r\n");
			//有三次输入机会
			int i = 0;
			for (i = 0; i < 3; i++)
			{
				scanf("%ld",&p_ass);
				if ( p->data.pass == p_ass )
				{
					printf("密码输入正确\r\n");
					//保存用户名
					strcpy(arr,buf);
					return OK;
				}
				printf("您输入的密码有误，请重新输入\r\n");
			}
			printf("您的输入次数已达到上限，请选择找回密码\r\n");	
			
			return ERROR;
		}
		//更新结点
		p = p->pNext;
	}
	printf("您输入的用户名不存在，请先申请\r\n");
	return ERROR;
	
}


//找回密码
int findPass( LIST * pList )
{
	//判断链表是否存在
	if ( NULL == pList )
	{
		return ERROR;
	}
	long int g_uard = 0;
	char buf[SIZE] = {0};
	
	//输入用户名比对
	printf("请输入用户名\r\n");
	scanf("%s",buf);
	
	//定义指针变量
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		//查找用户名存在
		if ( 0 == strcmp ( p->data.name, buf ) )
		{
			printf ( "==请输入密保，用于找回密码==\r\n");
			printf("你的出生日期是?\r\n");
			scanf ( "%ld", &g_uard );
			if ( p->data.guard == g_uard )
			{
				printf("您的密码是 %ld\r\n",p->data.pass);
				return  OK;	
			}
			printf("您输入的密保错误\r\n");
			return ERROR;
		}
		//更新结点
		p = p->pNext;
	}
	printf("您输入的用户名不存在，请先申请\r\n");
	return ERROR;
	
}




//申请账户
int applyFor( LIST * pList )
{
	//判断链表是否存在
	if ( NULL == pList )
	{
		return ERROR;
	}
	//新建结点
	LIST *p =  creation ( );
	if ( NULL == p )
	{
		return ERROR;
	}
	
	char buf[SIZE] = {0};
	//输入用户名比对
	printf("请输入用户名\r\n");
	scanf("%s",buf);
	
	
	//定义指针变量
	LIST *q = pList->pNext;
	while ( NULL != q )
	{
		//查找用户名存在
		if ( 0 == strcmp ( q->data.name, buf ) )
		{
			printf ( "%s 您的账号信息已经存在，请直接登录\r\n",buf );	
			return ERROR;
		}
		//更新结点
		q = q->pNext;
	}
	
	//用户不存在，申请账号
	strcpy(p->data.name,buf);

	printf ( "==请输入登录密码==\r\n");
	scanf ( "%ld", &p->data.pass );
	
	printf ( "==请输入密保，用于找回密码==\r\n");
	printf("你的出生日期是?\r\n");
	scanf ( "%ld", &p->data.guard );

	//头插法插入节点
	p->pNext = pList->pNext;
	pList->pNext = p;
	
	printf("%s 您的账户已经申请成功\r\n",buf);
	return OK;
}

	
//=================================================
	
/*
函数名：creation
函数功能：创建一个空结点
函数参数：无
函数返回值：创建成功返回结点的地址，失败返回NULL
*/

LIST * creation ( )
{
	//定义指针变量
	LIST *pList = NULL;
	//申请空间
	pList = ( LIST * ) malloc ( sizeof ( LIST ) );
	//判断，初始化
	if ( NULL == pList )
	{
		return NULL;
	}
	memset ( pList, 0, sizeof ( LIST ) );
	
	return pList;
}
	
		

/*
函数名：saveData
函数功能：保存数据，销毁结点
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

void saveData ( LIST *pList )
{
	//判断
	if ( NULL == pList 
	||   NULL == pList->pNext )
	{
		return ;
	}
	
	//定义一个文件指针
	FILE *fp =NULL;
	fp = fopen ( "../pass/pass.txt", "w+" );
	if ( NULL == fp )
	{
		printf( "文件打开失败\r\n" );
		return ;
	}
	//定义一个指针变量
	LIST *p = NULL;
	
	//保存完后销毁结点
	while ( NULL != pList->pNext )
	{	
		p = pList->pNext;
		pList->pNext = p->pNext;
		
		//保存数据
		fwrite(&p->data,sizeof(p->data),1,fp);
		//释放p
		free (p);
		p = NULL;
	}
	//销毁头结点
	free ( pList );
	pList = NULL;
	
	fclose ( fp );

	return;
}	
		

/*
函数名：readData
函数功能：读取数据
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

void readData ( LIST *pList )
{
	//判断
	if ( NULL == pList )
	{
		printf ( "读取数据失败！\r\n" );
		return ;
	}
	//定义一个文件指针
	FILE *fp = fopen ( "../pass/pass.txt", "rb" );
	if ( NULL == fp )
	{
		return ;
	}
	
	//定义指针变量
	LIST *p =  NULL;
	
	p = creation ( );
	fread(&p->data,sizeof(p->data),1,fp);
	
	while ( !feof(fp) )
	{	
			//头插法插入节点
			p->pNext = pList->pNext;
			pList->pNext = p;
			
			//创建一个结点
			p = creation ( );
			//赋值
			fread(&p->data,sizeof(p->data),1,fp);	
	}
	fclose ( fp );
	
	return;
}	
	




