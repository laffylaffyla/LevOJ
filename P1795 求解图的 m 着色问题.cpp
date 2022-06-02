/* 问题描述

给定无向连通图 G 和 m 种不同的颜色，用这些颜色为图 G 的各顶点着色，每个顶点着一种颜色。如果有一种着色法使 G 中每条边的两个顶点着不同颜色，则称这个图是 m 可着色的。图的 m 着色问题是对于给定图 G 和 m 种颜色，找出所有不同的着色法。

输入描述

第 1 行有 3 个正整数 n(1≤n≤20)、k 和 m(1≤m≤n)，表示给定的图 G 有 n 个顶点、k 条边、m 种颜色，顶点的编号为 1,2,…,n 在接下来的 k 行中每行有两个正整数 u,v，表示图 G 的一条边(u,v)。

输出描述

程序运行结束时将计算出的不同着色方案数输出。

Tip: 不能着色输出 0 即可。

样例输入

5 8 4
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5
样例输出

48 */
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 105
using namespace std;
int n, k, m, c[MAXN];
bool a[MAXN][MAXN];
int cnt = 0;
bool Same(int i)
{
    int j;
    for (j = 1; j <= n; j++)
    {
        if (j == i)
            continue;
        if (a[i][j] && c[i] == c[j])
            return false;
    }
    return true;
}

void dfs(int i)
{
    if (i > n)
    {
        cnt++;
        return;
    }
    else
    {
        for (int j = 1; j <= m; j++)
        {
            c[i] = j;
            if (Same(i))
                dfs(i + 1);
            c[i] = 0;
        }
    }
}

int main()
{
    int x, y;
    cin >> n >> k >> m;
    memset(a, false, sizeof(a));
    memset(c, 0, sizeof(c));
    for (int j = 1; j <= k; j++)
    {
        cin >> x >> y;
        a[x][y] = true;
        a[y][x] = true;
    }
    dfs(1);
    cout << cnt << endl;
    return 0;
}