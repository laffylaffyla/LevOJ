/*
题目描述
有 n 盏灯，编号为 1 ~ n。第 1 个人把所有灯打开，第 2 个人按下所有编号为 2 的倍数的开关（这些灯将被关掉），第 3 个人按下所有编号为 3 的倍数的开关（其中关掉的等将被打开，开着的灯将被关闭），以此类推。一共有 k 个人，问最后有哪些灯处于关闭状态？

输入描述
每组输入一行，包括用空格分开的 n 和 k（k <= n <= 1000）。

输出描述
处于关闭状态的灯编号。编号之间以空格分隔，第一个输出项之前和最后一个输出项之后不要空格。

样例输入
7 3
20 5

样例输出
2 3 4
2 3 5 9 12 14 20
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		bool* bulb = new bool[n + 1]();
		for (int i = 1; i <= k; i++)
		{
			for (int j = i; j <= n; j += i)
			{
				bulb[j] = !bulb[j];
			}
		}
		string ans;
		for (int i = 1; i <= n; i++)
		{
			if (!bulb[i])
			{
				ans += to_string(i);
				ans += " ";
			}
		}
		ans.pop_back();
		cout << ans << endl;
		delete[] bulb;
	}
	return 0;
}