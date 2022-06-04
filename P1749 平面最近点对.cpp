/* 题目描述

给定平面上 n 个点，找出其中的一对点的距离，使得在这 n 个点的所有点对中，该距离为所有点对中最小的。

输入格式

第一行一个整数 n，表示点的个数，n 不超过 10001。

接下来 n 行，每行两个实数 x,y，表示一个点的行坐标和列坐标。

输出格式

仅一行，一个实数，表示最短距离，四舍五入保留 4 位小数。

输入输出样例

3
1 1
1 2
2 2
输出

1.0000

说明 / 提示

数据规模与约定 对于
100% 的数据，保证 1≤n≤10^4,0≤x,y≤10^9，小数点后的数字个数是4。 */

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define INF 0x3f3f3f3f

int n;
double x[10003];
double y[10003];

double BAOLI_HAHAHA()
{
    double dist, min = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (dist < min)
                min = dist;
        }
    }
    return sqrt(min);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    printf("%.4lf\n", BAOLI_HAHAHA());
    return 0;
}
