/*************************************************************************
    > File Name: a.c
    > Author: X.price
    > Mail: 1450362882@qq.com 
    > Created Time: 2020年06月03日 星期三 18时56分38秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#define N 20
int main()
{
	char str1[N], str2[N];
	printf("请输入两个字符串：\n");
	scanf("%s%s",str1,str2);
	int t=strcmp(str1,str2);
	if(t==0)
		printf("str1=str2\n");
	else if(t>0)
		printf("st1>str2\n");
	else
		printf("str1<str2\n");
	return 0;
}
