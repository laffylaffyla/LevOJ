/* 题目描述

小胡同学在出题的时候感到有点饿，于是决定出去找点吃的。
小胡同学住在一条长长的公路的一头。为了方便行动，小胡同学找小水同学沿路安装了一些跳板。每个跳板能够将胡同学发射到一定距离内的任意位置。
在公路的另一头，有小胡同学很喜欢吃的炸鸡店。小胡同学想请你帮忙计算，在充分利用跳板的情况下，他要走多远才能到达炸鸡店。

输入描述
第一行两个整数 N 和 M 表示跳板的个数和炸鸡店到小胡同学家的距离
后面 N 行，第 i 行包含两个整数 Pi和 Xi表示第 i 个跳板安装在距离小胡同学家 Pi处，它能够发射的距离为 Xi
​
数据保证：
N≤10^5
N≤M
∀i<j,Pi<Pj
​0≤Pi≤M≤10^9
0<Xi≤10^9

输出描述
一个整数，表示胡同学要步行的距离。

样例输入 - 1

3 9
0 3
2 3
3 6

样例输出 - 1

0

样例输入 - 2

10 10
0 1
1 1
2 1
3 1
5 1
6 1
7 1
8 1
9 1
10 1

样例输出 - 2

1
 */

#include <iostream>

using namespace std;

#define N 1000000

int n, m;
int dp[N], p[N], x[N];

int dynamicProgramming(int n, int m, int p[], int x[])
{
    int s = 0;
    if (p[0] > 0)
        s = p[0];
    dp[0] = p[0] + x[0];
    for (int i = 0; i < n; i++)
    {
        if (dp[i] < p[i + 1])
        {
            s += p[i + 1] - dp[i];
            dp[i + 1] = p[i + 1] + x[i + 1];
        }
        else
        {
            if (dp[i] < p[i + 1] + x[i + 1])
                dp[i + 1] = p[i + 1] + x[i + 1];
            else
                dp[i + 1] = dp[i];
        }
    }
    if (dp[n - 1] < m)
        s += m - dp[n - 1];
    return s;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> p[i] >> x[i];
    cout << dynamicProgramming(n, m, p, x) << endl;
    return 0;
}