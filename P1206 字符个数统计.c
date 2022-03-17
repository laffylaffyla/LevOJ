#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>

int main()
{
	char a[101];
	char c;
	int i, sum, length;
	while (gets(a) != NULL)
	{
		sum = 0;
		length = 0;
		scanf("%c", &c);
		length = strlen(a);
		for (i = 0; i < length; i++)
		{
			if (a[i] == c)
				sum++;
		}
		printf("%d\n", sum);
		gets(a); //之前的换行符存在缓冲区，gets（）删除换行符
	}
	return 0;
}