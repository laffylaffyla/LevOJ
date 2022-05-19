/* 题目描述

三水最近在学习炼丹术。但是众所周知炼丹术是一门危险的学科，需要大量的调参才能保证安全。好在三水在洗衣机里面找到了一张失传已久的图纸，里面记录了若干种材料的药性。这张图纸上记录了 n 种不同的药材，对于每种药材，都需要恰好一种药材来使其稳定 (这种药材可能是其自身，即这种药材本身就很稳定)。三水想知道，通过这张图纸，可以得到多少种不同的稳定的丹方。保证每种药材只会作为稳定剂出现一次。

我们认为一个丹方是从 n 种药材中选择若干种 (不为 0 )，两个丹方被认为是不同的当且仅当存在一种药材在其中一个丹方中且不在另一个中。我们称一个丹方是稳定的，当且仅当所有出现在丹方中的药材的稳定剂也在药材中。

因为输出结果可能很大，所以答案对 998244353 取模。

输入描述

第一行一个数字 n ， 表示有 n(1⩽n⩽10^6) 种不同的药材。 接下来一行 n 个数字，第 i 数字 (1⩽ai⩽n) 表示药材 i 的稳定剂是 ai，保证输入是 1 到 n 的一个全排列。

输出描述
一个整数 n ，表示答案对 998244353 取模的结果。

样例输入

6
2 3 4 5 6 1
样例输出

1 */

#include <iostream>

using namespace std;

const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

int pre[MAXN], a[MAXN];

int find(int x)
{
    while (x != pre[x])
        x = pre[x] = pre[pre[x]];
    return x;
}

int pow(int n)
{
    int ans = 1, base = 2;
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans * base) % mod;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pre[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        int u = find(i), v = find(a[i]);
        if (u != v)
            pre[u] = v;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (pre[i] == i)
            cnt++;
    }
    cout << pow(cnt) - 1 << endl;
    return 0;
}