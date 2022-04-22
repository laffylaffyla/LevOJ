/* 问题描述
用 i 来表示 x 坐标轴上坐标为 (i−1,i)、长度为 1 的区间，并给出 n(1≤n≤200) 个不同的整数，表示 n 个这样的区间。现在要求画 m 条线段覆盖住所有的区间，条件是每条线段可以任意长，但是要求所画线段的长度之和最小，并且线段的数目不超过 m(l≤m≤50)。
Tip: 本题为单组输入

输入描述
第 1 行表示区间个数 n 和所需线段数 m, 第 2 行表示 n 个点的坐标。

输出描述
一行，输出 m 条线段的最小长度和。

样例输入

5 3
1 3 8 5 11

样例输出

7 */

#include <iostream>
#include <algorithm>

using namespace std;

int a[202], b[202];

int DES(int a, int b)
{
    return a > b;
}

int main()
{
    int n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    sum = a[n - 1] - a[0] + 1;
    for (int i = 0; i < n - 1; i++)
        b[i] = a[i + 1] - a[i] - 1;

    sort(b, b + n - 1, DES);
    for (int i = 0; i < m - 1; i++)
        sum -= b[i];

    cout << sum << endl;
    return 0;
}
