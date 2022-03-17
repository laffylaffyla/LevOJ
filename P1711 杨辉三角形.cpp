/*
下面的图形是著名的杨辉三角形： 如果我们按从上到下、从左到右的顺序把所有数排成一列，可以得到如下数列：1, 1, 1, 1, 2, 1, 1, 3, 3, 1, 1, 4, 6, 4, 1, …  给定一个正整数 N，请你输出数列中第一次出现 N 是在第几个数？

输入描述
单组输入，输入一个整数 N（1 ≤ N ≤ 1000000000）。

输出描述
输出一个整数代表答案

样例输入
6

样例输出
13
*/

#include<iostream>

using namespace std;

long long C(long long n, long long m)
{
	long long ans = 1;
	for (long long i = n, j = 1; i >= (n - m + 1); i--, j++)
	{
		ans = ans * i / j;
	}
	return ans;
}

long long Traversal(long long);

int main()
{
	long long n;
	while (cin >> n)
	{
		if (n == 1)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << Traversal(n) << endl; //o(n^3)
		}
	}
	return 0;
}

long long Traversal(long long n)
{
	for (long long i = 3;; i++)
		for (long long j = 1; j < i; j++)
		{
			if (C(i - 1, j) == n)
			{
				return (i - 1) * i / 2 + j + 1;
			}
		}
}