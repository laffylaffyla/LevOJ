/*
题目描述
给定两个数的分子和分母，求两个分数的和。

输入描述
多组输入，每组输入包含 44 个正整数 a, b, c, d (0 < a, b, c, d < 10000<a,b,c,d<1000)，依次代表第一个数的分子，第一个数的分母，第二个数的分子，第二个数的分母

输出描述
对于每组数据，输出的两个分数的和的最简分数形式。（如果分子是分母的倍数，则输出形式为 n/1 ）

样例输入

1 2 1 2
1 4 1 2

样例输出

1/1
3/4
*/

#include<iostream>
using namespace std;

int greatestCommonDivisor(int, int);

int main()
{
	int a, b, c, d;
	while (cin >> a >> b >> c >> d)
	{
		int numerator, denominator, temp;
		numerator = a * d + b * c;
		denominator = b * d;
		temp = greatestCommonDivisor(numerator, denominator);
		cout << numerator / temp
			<< '/'
			<< denominator / temp
			<< endl;
	}
	return 0;
}

int greatestCommonDivisor(int a, int b)
{
	int temp;
	if (a < b)
	{
		a ^= b ^= a ^= b;
	}
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}