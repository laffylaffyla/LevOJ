#define _CRT_SECURE_NO_WARNINGS

/*
题目描述
父母为儿子大学四年生活费存了一笔钱，方式是整存零取， 规定儿子每月月底取走下月的生活费 M 元。现在假设银行的年利率是 1.71%，现在计算母亲至少存多少钱？（保留 2 位小数）

输入描述
多组输入，每组一个整数 M，代表每月的生活费。

输出描述
父母亲一次性要存入的生活费（保留 2 位小数）

样例输入
3000
2000

样例输出
139089.86
92726.58
*/

#include<iostream>
#include<cstdio>

using namespace std;

#define Rate 0.0171

int main()
{
	int m;
	double deposit;
	while (cin >> m)
	{
		deposit = 0;
		for (int i = 48; i > 0; i--)
		{
			deposit += m;
			deposit /= 1 + (Rate / 12);
		}
		printf("%.2f\n", deposit);
	}
	return 0;
}