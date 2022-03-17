/*
题目描述
假设 2012 年 1 月 1 日是星期日，请求出 n 天后是星期几

输入描述
多组输入每组输入一个正整数 n (1≤n≤2000)

输出描述
对于每组输入，输出 1 个整数 i (1≤i≤7) , 表示 n 天后是星期几

样例输入

1
2

样例输出

1
2
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n <= 0)
		{
			cout << "Error, wrong number.";
			break;
		}
		while (n)
		{
			if (n > 7)
				n -= 7;
			if (n <= 7)
				break;
		}
		cout << n << endl;
	}
	return 0;
}