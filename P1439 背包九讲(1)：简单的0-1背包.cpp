/*
题目描述
有一个箱子容量为 V（正整数，0＜＝V＜＝20000），同时有 n 个物品（0＜n＜＝30），每个物品有一定的体积和价值。要求 n 个物品中，任取若干个装入箱内，在箱子能放得下的前提下，满足箱子内部的价值最大。

输入描述
一个整数 v，表示箱子容量
一个整数 n，表示有 n 个物品
接下来 n 个整数，分别表示这 n 个物品的各自体积和价值

输出描述
一个整数，表示箱子能装下的最大价值。

样例输入

3
2
2 100
4 200

样例输出

100

样例解释

输入：

3 // 箱子的总的容量为 3
2 // 一共有两个物品
2 100 // 第一个物品的体积为 2 价值为 100
4 200 // 第二个物品的体积为 4 价值为 200

输出:

100
在箱子能装下的前提下，应该选择第 1 个物品，最大的价值为 100
*/

#include <iostream>

using namespace std;

int main()
{
    int v, n;
    while (cin >> v >> n)
    {
        int *w = new int[n + 2];
        int *vi = new int[n + 2];
        int *dp = new int[n + 2];
        for (int i = 1; i <= n; i++)
            cin >> w[i] >> vi[i];
        for (int i = 1; i <= n; i++)
            for (int j = v; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + vi[i]);
        cout << dp[v] << endl;
        delete[] w;
        delete[] vi;
        delete[] dp;
    }
    return 0;
}
