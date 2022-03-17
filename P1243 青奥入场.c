#define _CRT_SECURE_NO_WARNINGS
/*
2014 年 8 月在南京举行第 2 届奥林匹克青年运动会，每个国家在报名参加时需要填写国家名字，参加的人数，所属的洲，同时系统会自动生成一个报名序号，在开幕式的运动员出场顺序上，按照国家名字的英文字母顺序来出场。请编写一个计算机程序实现国家名字的排序（升序），东道主中国（China）在最后一个出场

输入描述
多组输入，其中每组输入的第一行表示参加国家数 n（占一行），下面 n 行是国家的报名信息（序号、国家名称、参加人数、所属大洲）

输出描述
按国家名字的字母序输出信息（东道主国家名字最后输出）。

样例输入
5
1 France 123 Europe
2 Russia 254 Europe
3 Japan 235 Asia
4 Germany 185 Europe
5 China 560 Asia

样例输出
1 France 123 Europe
4 Germany 185 Europe
3 Japan 235 Asia
2 Russia 254 Europe
5 China 560 Asia
*/

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
	while (scanf("%d", &n) != EOF)
	{
		Info* info = (Info*)malloc(n * sizeof(Info));
		for (i = 0; i < n; i++)
			scanf("%d %s %d %s", &info[i].no, info[i].country, &info[i].people, info[i].continents);
		for (i = 0; i < n; i++)
			for (j = 0; j < n - i - 1; j++)
				if (strcmp(info[j + 1].country, "China") == 0)
					continue;
				else if (strcmp(info[j].country, info[j + 1].country) > 0 || strcmp(info[j].country, "China") == 0)
				{
					Info temp;
					temp = info[j];
					info[j] = info[j + 1];
					info[j + 1] = temp;
				}
		for (i = 0; i < n; i++)
			printf("%d %s %d %s\n", info[i].no, info[i].country, info[i].people, info[i].continents);
	}
	return 0;
}