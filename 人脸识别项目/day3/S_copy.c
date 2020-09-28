/*************************************************************************
    > File Name: S_copy.c
    > Author: X.price
    > Mail: 1450362882@qq.com 
    > Created Time: 2020年06月03日 星期三 19时01分30秒
 ************************************************************************/
#include <stdio.h>
char * strcpy(char*,const char*);
int main()
{	
	char B[30];
	char A[]="hello world,It's X.price";
        strcpy(B,A);
    	printf("%s\n",B);
}
char * strcpy(char * dest,const char * source)
{
	while(*dest++=*source++);
	return dest;
}
