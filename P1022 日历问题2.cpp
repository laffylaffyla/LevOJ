/*
题目描述
已知 2007 年 10 月 10 日，请求出 n 天后是几月几号

输入描述
多组输入，每组输入为 11 行，为一个正整数 nn (1≤n≤2000)

输出描述
对于每组输入，输出格式为 yyyy-mm-dd , 输出的值为 n 天后的日期

样例输入

1
2

样例输出

2007-10-11
2007-10-12
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	int yyyy = 2007,
		mm = 10,
		dd = 10;
	while (cin >> n)
	{
		if (n < 1)
		{
			cout << "Error, wrong number." << endl;
			break;
		}
		for (int i = 0; i < n; i++)
		{
			dd++;
			if ((yyyy % 4 == 0 && mm == 2) && dd == 30)
			{
				dd = 1;
				mm++;
			}
			else if ((yyyy % 4 != 0 && mm == 2) && dd == 29)
			{
				dd = 1;
				mm++;
			}
			else if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10) && dd == 32)
			{
				dd = 1;
				mm++;
			}
			else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd == 31)
			{
				dd = 1;
				mm++;
			}
			else if (mm == 12 && dd == 32)
			{
				yyyy++;
				mm = 1;
				dd = 1;
			}
		}
		cout << yyyy << "-"
			<< setw(2) << setfill('0') << mm << "-"
			<< setw(2) << setfill('0') << dd << endl;
		//reset
		yyyy = 2007;
		mm = 10;
		dd = 10;
	}
	return 0;
}