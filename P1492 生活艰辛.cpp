/*
题目描述
写字楼里写字间，
写字间里程序员。
程序人员写程序，
又拿程序换房钱。
某程序员开始工作，第一年年薪 N 万，他希望在新区买一套 60 平米，现价为 200 万的房子。假设房子价格以每年 K 万元增长，并且该程序员未来税后年薪不变，且不吃不喝，每年所得 N 万全都积攒起来，问第几年能够买下这套房子？

输入描述
有多组测试数据，每组测试数据占一行。

每一行包含两个正整数 N (10 ≤ N ≤ 50) 和 K (1 ≤ K ≤ 20)，中间用单个空格隔开。

输出描述
如果在第 20 年或者之前就能买下这套房子，则输出一个整数 M，表示最早需要在第 M 年能买下，否则输出 "Impossible"。

样例输入
50 10
12 2
1 5

样例输出
5
20
Impossible
*/

/*
写字楼里写字间，
写字间里程序员。
程序人员写程序，
又拿程序换房钱。
*/

#include <iostream>
//#include<好日子还在后头咧.jpg>

using namespace std;

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int netIncome, finalDeposite, year = 0, deposite = 0;
        netIncome = n - k;
        if (netIncome <= 0)
        {
            cout << "Impossible" << endl;
            continue;
        }
        else
        {
            finalDeposite = netIncome * 20;
            if (finalDeposite >= 200)
            {
                while (deposite < 200)
                {
                    deposite += netIncome;
                    year++;
                }
                cout << year << endl;
                continue;
            }
            else
            {
                cout << "Impossible" << endl;
                continue;
            }
        }
    }
	return 0;
}