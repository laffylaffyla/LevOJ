/*
题目描述
设有 n 条封闭曲线画在平面上，而任何两条封闭曲线恰好相交于两点，且任何三条封闭曲线不相交于同一点，求这些封闭曲线把平面分割成的区域个数。

输入描述
多组输入，每组输入一个正整数 n，表示封闭曲线的条数。

输出描述
输出封闭曲线把平面分割成的区域数

样例输入

6
10

样例输出

32
92
*/

#include<iostream>

using namespace std;

long long a[10005];

int main()
{
	int n;
	while (cin >> n)
	{
		a[0] = 0;
		a[1] = 2;
		for (int i = 2; i <= n; i++)
			a[i] = a[i - 1] + 2 * (i - 1);
		cout << a[n] << endl;
	}
	return 0;
}