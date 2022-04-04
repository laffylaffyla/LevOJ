/*
有一个 n 个点 m 条边的无向图，请求出从 s 到 t 的最短路长度。

输入格式
第一行四个正整数 n, m, s, t。 接下来 m 行，每行三个正整数 u, v, w，表示一条连接 u, v 长为 w 的边。
1≤n≤2500，1≤m≤6200，1≤w≤1000。

输出格式
输出一行一个整数，表示答案。

样例输入

7 11 5 4
2 4 2
1 4 3
7 2 2
3 4 3
5 7 5
7 3 3
6 1 1
6 3 4
2 4 3
5 6 3
7 2 1

样例输出

7
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

struct edge
{
    int to;
    int next;
    int cost;
} e[16384];

int n, m, s, t;
int head[3000];
int cnt;
int dis[3000];

struct cmp
{
    bool operator()(int x, int y)
    {
        return dis[x] > dis[y];
    }
};

void addEdge(int u, int v, int t)
{
    e[cnt].to = v;
    e[cnt].cost = t;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void Dijkstra()
{
    priority_queue<int, vector<int>, cmp> qe;
    dis[s] = 0;
    qe.push(s);
    while (!qe.empty())
    {
        int u = qe.top();
        qe.pop();
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[u] + e[i].cost < dis[v])
            {
                dis[v] = dis[u] + e[i].cost;
                qe.push(v);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s >> t;
    memset(dis, INF, sizeof(dis));
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    Dijkstra();
    cout << dis[t] << endl;
    return 0;
}