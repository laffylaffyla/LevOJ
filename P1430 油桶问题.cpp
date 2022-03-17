/*
题目描述：
饭店的大师傅老蔡正准备炒菜，而徒弟小刚正在和几个服务员微信聊天和抢红包，老蔡发现炒菜没油了，高喊小刚去储藏室里倒油，小刚走进储藏室看到有 n 个油桶都装满了油，这 n 个油桶容积 (整数) 大小各不相同，小刚需要 m 升 (整数) 油，请你不借助任何其他容器，能否直接从 n 桶油中任意取 k 桶 (1<=k<=n) 油，其油的总量正好时 m 升，如果可以就输出 “yes”，否则输出 “no”

输入描述
多组输入第一行两个整数 n，m。第二行 n 个整数，即油桶的容积。

输出描述
一行 yes 或 no

样例输入：
5 10
1 2 3 1 1
6 11
3 5 3 2 1 4

样例输出：
no
yes
*/

#include<iostream>

using namespace std;

int p(int, int, int*);

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int* a = new int[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (p(n, m, a) == 0)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
		delete[] a;
	}
	return 0;
}

int p(int n, int m,int* a)
{
	if (n == 0 || m < 0)
		return 0;
	else
	{
		if (m == a[n])
			return 1;
		else
		{
			if (p(n - 1, m - a[n], a) == 1)
				return 1;
			if (p(n - 1, m, a) == 1)
				return 1;
		}
	}
	return 0;
}