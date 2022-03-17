/*
题目描述
古希腊数学家毕达哥拉斯在自然数研究中发现，220 的所有真约数 (即不是自身的约数) 之和为： 1+2+4+5+10+11+20+22+44+55+110＝284。 而 284 的所有真约数为 1、2、4、71、 142，加起来恰好为 220。人们对这样的数感到很惊奇，并称之为亲和数。一般地讲，如果两个数中任何一个数都是另一个数的真约数之和，则这两个数就是亲和数。你的任务就编写一个程序，判断给定的两个数是否是亲和数。

输入描述
输入数据第一行包含一个数 M，接下有 M 行，每行一个实例，包含两个整数 A,B； 其中 0 <= A,B <= 600000 ;

输出描述
对于每个测试实例，如果 A 和 B 是亲和数的话输出 Yes，否则输出 No。

样例输入

2
220 284
100 200

样例输出

Yes
No
*/

#include<iostream>

using namespace std;

int AmicableNumber(int);

int main()
{
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (AmicableNumber(a) == b && AmicableNumber(b) == a)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

int AmicableNumber(int n)
{
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			ans += i;
	return ans;
}