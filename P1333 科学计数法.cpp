/*
[2017 NUIST 程序设计竞赛 模拟赛]
B. 科学计数法
题目描述
众所周知，任意大的整数均可用科学计数法近似地表示。现请你用科学计数法表示出 a 的 b 次方的结果

输入描述
有多组输入。在每一组输入中，有一个正整数 a 和 一个非负整数 b (a 和 b 小于 2 的 26 次方)。

输出描述
对于每一组输入，输出一行结果。结果表示为 "m*10^n" 的形式。其中，m 四舍五入保留至小数点后三位。输出中没有多余的空格。

输入样例
3 5
2 128
255 0
31415926 27182818

输出样例
2.430*10^2
3.403*10^38
1.000*10^0
2.027*10^203793660
*/

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		int index = 0, tempIndex = 0;
		double baseNumber = 1, tempBaseNumber;
		tempBaseNumber = a;
		while (tempBaseNumber >= 10)
		{
			tempBaseNumber /= 10;
			tempIndex++;
		}
		while (b)
		{
			if (b % 2)
			{
				baseNumber *= tempBaseNumber;
				index += tempIndex;
			}
			while (baseNumber >= 10)
			{
				baseNumber /= 10;
				index++;
			}
			tempBaseNumber *= tempBaseNumber;
			tempIndex *= 2;
			while (tempBaseNumber >= 10)
			{
				tempBaseNumber /= 10;
				tempIndex++;
			}
			b /= 2;
		}
		cout << fixed << setprecision(3) << baseNumber << "*10^" << index << endl;
	}
	return 0;
}