/* 题目描述

输入一个 C 个点 S 条边的无向带权图，边权表示该路径上的噪声值。当噪声值太大时，耳膜可能会受到伤害，所以当你从某点去往另一个点时，总是希望路上经过的最大噪声值最小。输入一些询问，每次询问两个点，输出这两个点间「最大噪声值最小的路径」上，噪声值最大的一条边的噪声值。

如果两个点之间不连通，输出 "no path"。(不含引号)

输入描述
本题包含多组输入。

每组数据第一行含有 3 个整数：C，S，Q，分别表示点数、边数和询问数量。

接下来 S 行，每行三个整数 u，v，w，表示一条两端点为 u，v，噪声值为 w 的无向边。
之后的 Q 行，每行两个整数 a，b，询问从 a 到 b，「最大噪声值最小的路径」的「最大噪声值」。（ C≤100，S≤1000，Q≤10000 ）

输出描述
每组数据输出的起始部分，输出一行数据编号 (从 1 开始计数)。
对每次询问，若两点连通，输出两点间「最大噪声值最小的路径」的「最大噪声值」。否则输出 "no path"。
详见样例。

样例输入

6 6 1
5 1 5
6 1 4
2 1 3
3 6 7
3 4 6
3 1 8
2 5
5 4 2
4 1 9
5 1 4
2 1 3
3 4 7
4 5
4 5

样例输出

Case #1
5
Case #2
9
9 */

#include <iostream>
#define INF 0x3f3f3f3f
#define MAXN 102

using namespace std;

int map[MAXN][MAXN], n, m, q, u, v, l;

void init()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            map[i][j] = i == j ? 0 : INF;
}
inline int Max(int a, int b)
{
    return a > b ? a : b;
}
inline int Min(int a, int b)
{
    return a < b ? a : b;
}

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                map[i][j] = Min(map[i][j], Max(map[i][k], map[k][j]));
}

int main()
{
    int cas = 1;
    while (cin >> n >> m >> q)
    {
        init();
        while (m--)
        {
            cin >> u >> v >> l;
            if (map[u][v] > l)
            {
                map[u][v] = l;
                map[v][u] = l;
            }
        }
        cout << "Case #" << cas << endl;
        floyd();
        while (q--)
        {
            cin >> u >> v;
            if (map[u][v] >= INF)
                cout << "no path" << endl;
            else
                cout << map[u][v] << endl;
        }
        cas++;
    }
    return 0;
}