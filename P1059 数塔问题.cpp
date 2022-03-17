/*
从数塔顶层出发，每个结点可以选择向左走或向右走，要求一直走到塔底，使得走过的路径上的数值和最小.

例如对于下面这样的数塔


1
2  3
4  5  6
按照 1 - 2 - 4 的路线走，可取得路径上的数值和的最小值为 7

输入描述
每组输入的第一行表示数塔的行数，最大不超过 1000 行.

后面每行为这个数塔特定行包含的正整数。这些正整数不大于 10000 .

输出描述
对于每组测试数据，输出一行答案.

样例输入

3
1
2 3
4 5 6

样例输出

7
*/

#include<iostream>

using namespace std;

int main()
{
	int n;
	int(*a)[1001] = new int[1001][1001];
	//initialize array
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			a[i][j] = 0;

	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				cin >> a[i][j];

		for (int i = n - 1; i >= 1; i--)
			for (int j = 1; j <= i; j++)
			{
				if (a[i + 1][j] < a[i + 1][j + 1])
					a[i][j] += a[i + 1][j];
				else
					a[i][j] += a[i + 1][j + 1];
			}
		cout << a[1][1] << endl;
		//reset array
		for (int i = 0; i < 1001; i++)
			for (int j = 0; j < 1001; j++)
				a[i][j] = 0;
	}
	return 0;
}