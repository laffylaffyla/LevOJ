/*
题目描述
给定一个正整数，写出它的 2 进制表示

输入描述
多组输入，输入的第一行为一个正整数 n，表示接下来有 n 组数据，每一行为 1 个正整数 a (0<a≤10000)

输出描述
对于每一组数据，求出 a 的 2 进制表示法

样例输入

2
5
10

样例输出

101
1010
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int bin(int n)
{
	if (n < 2)
		return n;
	else
		return bin(n / 2) * 10 + n % 2;
}

int main()
{
	int i, t;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		int a;
		scanf("%d", &a);
		printf("%d\n", bin(a));
	}
}