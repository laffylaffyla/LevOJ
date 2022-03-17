#define _CRT_SECURE_NO_WARNINGS
/*
题目描述：
有理数的分数表示方法简洁清晰。计算时，我们通常需要利用有理数的小数形式。现在给定一个分数式和有理数的小数点后的位数，请计算出这个分数的数值

输入：
每行一个分数式和小数点后的位数，其中分子 n 和分母 m 的值均 <=60000，小数点的位数 t<=100

输出：
每行一个分数的值，若不是循环小数，则无须输出多余的 0。最后一位无须四舍五入

样例输入：
1/2 10
11/19 20
101/19 10

样例输出：
0.5
0.57894736842105263157
5.3157894736
*/

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int numerator, denominator, n, temp;
	while (scanf("%d/%d%d", &numerator, &denominator, &n) != EOF)
	{
		cout << numerator / denominator << ".";
		temp = numerator % denominator;
		while (n && temp)
		{
			temp *= 10;
			cout << temp / denominator;
			temp %= denominator;
			n--;
		}
		cout << endl;
	}
	return 0;
}