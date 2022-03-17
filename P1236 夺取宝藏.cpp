/*
[2014 NUIST 程序设计竞赛]
H. 夺取宝藏

题目描述
Ipomy 现在来到了阿兹特克宝藏堆中。这些宝藏散落放在一个 m * n 的网格上，每个宝藏都有一个价值。Ipomy 自然是希望将所有宝藏统统拿走，但他在走出迷宫时，不小心中了魔咒，一次只能向下或向右移动一步。假设 Ipomy 身处网格的左上角，而古城的出口在右下角，他想在离开古城前，拿到价值之和尽可能大的宝藏。请你编写程序，帮助他计算他可以拿到的最大价值之和。

样例解释
一路向下走，取到 4 和 8，接着一路向右走，取到 9, 10 和 11，价值之和为 42。

输入描述
多组输入。
每组输入的第一行为两个整数 m 和 n，用来描述网格的规格。保证 1 <= m, n <= 1000。
接下来的 m 行，每行 n 个整数，表示每个格子上面的宝藏的价值。输入数据保证 Ipomy 起始所在处没有宝藏，即价值为 0，以及每个宝藏的价值均在 int 型的表示范围内。

输出描述
多组输出。
每组输出占据一行，为一个整数，表示最大的价值之和。

样例输入
3 4
0 5 2 3
4 5 6 7
8 9 10 11

样例输出
42
*/

#include <iostream>

using namespace std;

int map[1002][1002];

int maxValue(int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            int max1 = 0;
            int max2 = 0;
            if ((i - 1) >= 0)
            {
                max1 = map[i - 1][j] + map[i][j];
            }
            if ((j - 1) >= 0)
            {
                max2 = map[i][j - 1] + map[i][j];
            }
            map[i][j] = max(max1, max2);
        }
    return map[m - 1][n - 1];
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
            }
        cout << maxValue(m, n) << endl;
    }
    return 0;
}