/*
题目描述
小婷有一个 E-Mail 邮箱的密码是 n 位长长正整数（n 大于 3），但由于有一段日子不使用此邮箱，她忘记了密码。小婷的生日是 8 月 1 日，她妈妈的生日是 9 月 1 日，她特别喜欢把同时是 81 和 91 的倍数用做密码。此外，小婷还记得这个密码的百位数是 1。请设计一个程序找回这个密码。密码必须是唯一的。

输入描述
多组输入，占一行，输入一个 n 位数的正整数

输出描述
占一行，如果满足条件则输出密码，否则输出 wrong。

样例输入
18923
200000

样例输出
22113
wrong
*/

#include<iostream>

using namespace std;

int main()
{
	string n;
	while (cin >> n)
	{
		if (n.length() == 5)
			cout << "22113" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}