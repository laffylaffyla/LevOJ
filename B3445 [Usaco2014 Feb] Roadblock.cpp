/*
题目描述
有一个无向图，共 N 个节点，编号 1 至 N，共 M 条边。FJ 在节点 1，它想到达节点 N。FJ 总是会选择最短路径到达节点 N。作为捣蛋的奶牛 Bessie，它想尽量延迟 FJ 到达节点 N 的时间，于是 Bessie 决定从 M 条边之中选择某一条边，使得改边的长度变成原来的两倍，由于智商的问题，Bessie 不知道选择加倍哪条边的长度才能使得 FJ 到达 N 号节点的时间最迟。注意：不管 Bessie 选择加倍哪条边的长度，FJ 总是会从 1 号节点开始走最短路径到达 N 号点。

输入格式
第一行，两个整数 N 和 M. 1 <=N<=250, 1<=M<=250000。
接下来有 M 行，每行三个整数：A，B，L，表示节点 A 和节点 B 之间有一条长度为 L 的无向边。1<=L<=1000000。

输出格式
一个整数。Bessie 选择了加倍某一条边的长度后，奶牛 FJ 从节点 1 到达节点 N 的最短路径是多少。但是输出的格式有变化，假设 Bessie 没有加倍某一条边的长度之前，FJ 从 1 号节点到达 N 号节点的最短路径是 X；在 Bessie 加倍某一条边的长度之后，FJ 从 1 号节点到达 N 号节点的最短路径是 Y，那么你输出的结果是 Y-X。

样例输入

5 7
2 1 5
1 3 1
3 2 8
3 5 7
3 4 3
2 4 7
4 5 2

INPUT DETAILS: There are 5 fields and 7 pathways. Currently, the shortest path from the house (field 1) to the barn (field 5) is 1-3-4-5 of total length 1+3+2=6.

样例输出

2
（把节点 3 到节点 4 的边从原来的长度 3 变成长度 6）
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 255, MAXM = 250005;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct Edge
{
    int nxt, to;
    long long val;
    Edge(int NXT = 0, int TO = 0, long long VAL = 0ll)
    {
        nxt = NXT;
        to = TO;
        val = VAL;
    }
} e[MAXM << 1];

int n, m, cnt = 1;
int head[MAXN], pre[MAXN], frm[MAXN];
bool vis[MAXN];
long long org, ans, dst[MAXN];
priority_queue<pair<long long, int>> q;

void addEdge(int a, int b, long long l)
{
    e[++cnt] = Edge(head[a], b, l);
    head[a] = cnt;
    return;
}
void Dijkstra()
{
    for (int i = 1; i <= n; ++i)
        dst[i] = INF;
    dst[1] = 0ll;
    q.push(make_pair(0, 1));
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = head[x]; i; i = e[i].nxt)
        {
            int y = e[i].to;
            if (dst[y] > dst[x] + e[i].val)
            {
                dst[y] = dst[x] + e[i].val;
                frm[y] = i;
                pre[y] = x;
                q.push(make_pair(-dst[y], y));
            }
        }
    }
    org = dst[n];
    return;
}
void Dijkstra2()
{
    for (int i = 1; i <= n; ++i)
        dst[i] = INF, vis[i] = false;
    dst[1] = 0ll;
    q.push(make_pair(0, 1));
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = head[x]; i; i = e[i].nxt)
        {
            int y = e[i].to;
            if (dst[y] > dst[x] + e[i].val)
            {
                dst[y] = dst[x] + e[i].val;
                q.push(make_pair(-dst[y], y));
            }
        }
    }
    return;
}
void work()
{
    for (int y = 1; y <= n; ++y)
    {
        int x = pre[y], i = frm[y];
        e[i].val <<= 1;
        e[i ^ 1].val <<= 1;
        Dijkstra2();
        ans = max(ans, dst[n]);
        e[i].val >>= 1;
        e[i ^ 1].val >>= 1;
    }
    return;
}

int main()
{
    cin >> n >> m;
    int a, b;
    long long l;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> l;
        addEdge(a, b, l);
        addEdge(b, a, l);
    }
    Dijkstra();
    work();
    cout << ans - org << endl;
    return 0;
}
