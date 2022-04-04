/*
题目描述
Bessie 计划调查 N（2≤N≤2000）个农场的干草情况，它从 1 号农场出发。农场之间总共有 M（1≤M≤10^4）条双向道路，所有道路的总长度不超过 10^9。有些农场之间存在着多条道路，所有的农场之间都是连通的。
Bessie 希望计算出该图中最小生成树中的最长边的长度。

输入格式

第 1 行输入两个整数 N 和 M; 接下来 M 行，每行输入三个整数，表示一条道路的起点终点和长度。

输出格式
一个整数，表示最小生成树中的最长边的长度。

样例输入

3 3
1 2 23
2 3 1000
1 3 43

样例输出

43

提示
由 1 到达 2，需要经过长度 23 的道路；回到 1 再到 3，通过长度 43 的道路．最长道路为 43
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct edge
{
    int u, v, w;
} e[10086];

int n, m;
int fa[2048];
int ans;

int find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void kruskal()
{
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int eu = find(e[i].u), ev = find(e[i].v);
        if (eu == ev)
            continue;
        fa[ev] = eu;
        if (++cnt == n - 1)
        {
            ans = e[i].w;
            break;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e + 1, e + m + 1, cmp);
    kruskal();
    cout << ans << endl;
    return 0;
}
