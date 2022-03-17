/*
题目描述
从一组数据（长度为 n，其中 n <= 10000，数据的值都大于 -60000）中找出连续的一段数，使得这段数的和最大。

输入描述
第一行是一个正整数 n，表示数据的个数，从第二行开始是 n 个数据。

输出描述
一行，子段的最大和。

样例输入
5
1 -3 4 1 -9

样例输出
5
*/

#include<iostream>

using namespace std;

int main()
{
	int n, a, count = 0, max = 0;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			count += a;
			if (count > max)
				max = count;
			if (count < 0)
				count = 0;
		}
		cout << max << endl;
	}
	return 0;
}