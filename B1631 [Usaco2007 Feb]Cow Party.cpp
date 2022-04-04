/*
题目描述
寒假到了，n 头牛都要去参加一场在编号为 x 的牛的农场举行的派对，农场之间有 m 条有向路，每条路都有一定的长度。
每头牛参加完派对后都必须回家，无论是去参加派对还是回家，每头牛都会选择最短路径，求这 n 头牛的最短路径（一个来回）中最长的一条路径长度。

输入格式
第一行有三个整数，分别表示牛的数量 n，道路数 m 和派对农场编号 x。

接下来 m 行，每行三个整数 u, v, w 表示存在一条由 u 通向 v 的长度为 w 的道路。
对于全部的测试点，保证1≤x≤n≤10^3，1≤m≤10^5 ，1≤u,v≤n，1≤w≤10^2，保证从任何一个结点出发都能到达 x 号结点，且从 x 出发可以到达其他所有节点。

输出格式
输出一行一个整数表示答案。

样例输入
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

样例输出
10

提示
样例说明:
共有 4 只奶牛参加聚会，有 8 条路，聚会位于第 2 个农场.
第 4 只奶牛可以直接到聚会所在地 (花费 3 时间), 然后返程路线经过第 1 和第 3 个农场 (花费 7 时间), 总共 10 时间.

*/
#include <iostream>
#include <algorithm>

#define INF 0x3f3f3f3f
#define MaxN 1024

using namespace std;

int map[MaxN][MaxN], n;
int way[MaxN], distances[MaxN];

void dijkstra(int x)
{
    int visit[MaxN] = {0};
    int min, next = x;
    for (int i = 1; i <= n; ++i)
        distances[i] = map[x][i];
    visit[x] = 1;
    for (int i = 2; i <= n; ++i)
    {
        min = INF;
        for (int j = 1; j <= n; ++j)
        {
            if (!visit[j] && distances[j] < min)
            {
                min = distances[j];
                next = j;
            }
        }
        visit[next] = 1;
        for (int j = 1; j <= n; ++j)
        {
            if (!visit[j] && distances[j] > distances[next] + map[next][j])
                distances[j] = distances[next] + map[next][j];
        }
    }
}

int main()
{
    int m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i != j)
                map[i][j] = INF;
            else
                map[i][j] = 0;
        }
    }
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        if (w < map[u][v])
            map[u][v] = w;
    }
    dijkstra(x);
    for (int i = 1; i <= n; ++i)
        way[i] = distances[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int temp;
            temp = map[j][i];
            map[j][i] = map[i][j];
            map[i][j] = temp;
        }
    }
    dijkstra(x);
    for (int i = 1; i <= n; ++i)
    {
        if (i != x)
            ans = max(ans, way[i] + distances[i]);
    }
    cout << ans << endl;
    return 0;
}