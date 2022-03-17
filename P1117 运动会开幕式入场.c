#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct infomation
{
	int no;
	char country[16];
	int people;
	char continents[16];
}Info;

int main()
{
	int n, i, j;
	scanf("%d", &n);
	Info* info = (Info*)malloc(n * sizeof(Info));
	//循环输入数据
	for (i = 0; i < n; i++)
		scanf("%s", info[i].country);

	//冒泡排序
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (strcmp(info[j + 1].country, "China") == 0)//如果第二个字符串是China则跳过
				continue;
			else if (strcmp(info[j].country, info[j + 1].country) > 0 || strcmp(info[j].country, "China") == 0)
			{  //前面的字符串比后面的小或者前面的字符串是China
				char temp[16] = { 0 };
				strcpy(temp, info[j].country);
				strcpy(info[j].country, info[j + 1].country);
				strcpy(info[j + 1].country, temp);
			}
		}
	}

	//打印结果
	for (i = 0; i < n; i++)
		printf("%s\n", info[i].country);
}