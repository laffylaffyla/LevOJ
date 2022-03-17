/*
题目描述
小明刚放学回家，老妈就吩咐他：马上有客人要来，赶快把苹果洗了放到盘子里去。小明要把 m 个同样的苹果放到 n 个同样的盘子里，允许有的盘子空着不放，有多少种不同的 分法。5,1,1 与 1,5,1 是同一种放法。

输入描述
多组输入，输入两个数 m 和 n 代表苹果数和盘子数

输出描述
对于每一组数，有多少种不同的放法

样例输入
7 3

样例输出
8
*/

#include<iostream>

using namespace std;

int allocatedSolution(int, int);

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		cout << allocatedSolution(m, n) << endl;
	}
	return 0;
}

int allocatedSolution(int m, int n)
{
	if (m == 0 || n == 1)
		return 1;
	if (m < n)
		return allocatedSolution(m, m);
	else
		return allocatedSolution(m, n - 1) + allocatedSolution(m - n, n);
}