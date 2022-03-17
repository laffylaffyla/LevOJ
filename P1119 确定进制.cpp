/*
题目描述
6 × 9 = 42 对于十进制来说是错误的，但是对于 13 进制来说是正确的。即，6 (13) × 9 (13) = 42 (13)， 而 42 (13) = 4 × 13 + 2 = 54 (10)。

你的任务是写一段程序读入三个整数 p, q 和 r，然后确定一个进制 B (2 <= B <= 16) 使得 p × q = r。如果 B 有很多选择，输出最小的一个。

例如：当 p = 11, q = 11, r = 121 时，则有 11 (3) × 11 (3) = 121 (3)。因为 11 (3) = 1 × 31 + 1 × 30 = 4 (10) 且 121 (3) = 1 × 32 + 2 × 31 + 1 × 30 = 16 (10)。对于进制 10，有 11 (10) × 11 (10) = 121 (10)。这种情况下，应该输出 3。如果没有合适的进制，则输出 0。

输入描述
输入有 T 组测试样例。T 在第一行给出。每一组测试样例占一行，包含三个整数 p, q, r。 p, q, r 的所有位都是数字，并且 1 <= p, q, r <= 1,000,000。

输出描述
对于每个测试样例输出一行。该行包含一个整数，即使得 p × q = r 成立的最小的 B。如果没有合适的 B，则输出 0。

样例输入

3
6 9 42
11 11 121
2 2 2

样例输出

13
3
0
*/

#include<iostream>

using namespace std;

int ConversionOfNumberSystem(int x, int B);

int main()
{
	int t, p, q, r;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> p >> q >> r;
		int ans = 0;
		for (int j = 2; j <= 16; j++)
			if (ConversionOfNumberSystem(p, j) * ConversionOfNumberSystem(q, j) == ConversionOfNumberSystem(r, j))
			{
				ans = j;
				break;
			}
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}

int ConversionOfNumberSystem(int x, int B)
{
	int value = 1, num = 0;
	while (x != 0)
	{
		if ((x % 10) >= B)
			return 114514;
		num += ((x % 10) * value);
		value *= B;
		x /= 10;
	}
	return num;
}