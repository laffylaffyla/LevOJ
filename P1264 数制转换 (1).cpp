/*
题目描述
在实际的应用中，数制转换是常用的技巧，现在需要完成 P 数制数转换为 R 进制数的问题 (2 <= P, R <= 16)

输入描述
每行包含三个数据 p, r, n, 分别是 p 进制，r 进制，待转换的 p 进制数 n（n 的十进制表示小于 10 ^ 8）

当输入 0 0 0 时，表示输入结束，无须处理。

输出描述
每行一个数，表示进制转换的结果

样例输入
10 16 155
16 8 1A
0 0 0

样例输出
9B
32
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

int AnyNumSysToDec(int, string);
void DecToAppointedNumSys(int, int);

int main()
{
	int p, r;
	string n;
	while (cin >> p >> r >> n)
	{
		if (p == 0)
			return 0;
		DecToAppointedNumSys(r, AnyNumSysToDec(p, n));
		cout << endl;
	}
	return 0;
}

int AnyNumSysToDec(int b, string n)
{
	int ans = 0, i = 0;
	while (n.size() != i)
	{
		ans *= b;
		if (n[i] >= '0' && n[i] <= '9')
			ans += n[i] - '0';
		else if (n[i] >= 'A' && n[i] <= 'Z')
			ans += n[i] - 55;
		else if (n[i] >= 'a' && n[i] <= 'z')
			ans += n[i] - 87;
		i++;
	}
	return ans;
}

void DecToAppointedNumSys(int b, int n)
{
	int m = 0, temp, s[1000];
	while (n != 0) 
	{
		temp = n % b;
		n = n / b;
		m++;
		s[m] = temp;
	}

	for (int k = m; k >= 1; k--)
	{
		if (s[k] >= 10)
			cout << (char)(s[k] + 55);
		else
			cout << s[k];
	}
}