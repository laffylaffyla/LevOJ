/*
题目描述

阿里巴巴走进了装满宝藏的藏宝洞。藏宝洞里面有
N(N≤100) 堆金币，第 i 堆金币的总重量和总价值分别是 mi,vi(1≤mi,vi≤100)。阿里巴巴有一个承重量为 T(T≤1000) 的背包，但并不一定有办法将全部的金币都装进去。他想装走尽可能多价值的金币。所有金币都可以随意分割，分割完的金币重量价值比（也就是单位价格）不变。请问阿里巴巴最多可以拿走多少价值的金币？

输入描述

第一行两个整数 N,T。
接下来 N 行，每行两个整数 mi,vi​。

输出描述
一个实数表示答案，输出两位小数。

样例输入
4 50
10 60
20 100
30 120
15 45

样例输出
240.00
*/

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct coin
{
    double weight;
    double value;
    double valuePerWeight;
} treasure[102];

bool cmp(coin a, coin b)
{
    return a.valuePerWeight > b.valuePerWeight;
}

double fractional_knapsack(int n, int t, coin treasure[])
{
    double totalValue = 0, remainingCapacity = t;
    for (int i = 0; i < n; i++)
    {
        if (remainingCapacity >= treasure[i].weight)
        {
            remainingCapacity -= treasure[i].weight;
            totalValue += treasure[i].value;
        }
        else
        {
            totalValue += remainingCapacity * treasure[i].valuePerWeight;
            break;
        }
    }
    return totalValue;
}

int main()
{
    int n;
    double t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> treasure[i].weight >> treasure[i].value;
        treasure[i].valuePerWeight = treasure[i].value / treasure[i].weight;
    }
    sort(treasure, treasure + n, cmp);
    cout << fixed << setprecision(2) << fractional_knapsack(n, t, treasure) << endl;
    return 0;
}