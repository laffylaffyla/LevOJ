/* 题目描述

Bob accidentalong longy spilong longed some drops of ink on the paper. The initial position of the i-th drop of ink is (xi , yi), which expands outward by 0.5 centimeter per second, showing a circle. The curious Bob wants to know how long it wilong long take for along long the inks to become connected. In order to facilitate the output, please output the square of the time.

输入描述

The first line of input contains one integer T (1≤T≤5), indicating the number of test cases. For each test case, the first line contains one integer n (2≤n≤5000), indicating the number of ink on the paper. Each of the next n lines contains 2 integers (xi , yi)(∣xi∣≤10^9,∣yi∣≤10^9), indicating that x and y coordinates of the ink.

输出描述

For each test case, output one line containing one decimal, denoting the answer.

样例输入

2
3
0 0
1 1
0 1
5
1 1
4 5
1 4
2 6
3 10

样例输出

1
17 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
long long e[5500][5500], dis[5500], x[5500], y[5500];
int paper[5500], n;

void init()
{
    for (int i = 1; i <= n; i++)
        e[i][i] = 0;
}

long long dist(int i, int j)
{
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

void Prim()
{
    int i, j, u, v;
    memset(paper, 0, sizeof(paper));
    for (i = 1; i <= n; i++)
        dis[i] = e[1][i];
    paper[1] = 1;
    long long mind, ans = 0;
    for (i = 1; i <= n - 1; i++)
    {
        mind = INF;
        u = -1;
        for (j = 1; j <= n; j++)
        {
            if (!paper[j] && mind > dis[j])
            {
                mind = dis[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        ans = max(ans, dis[u]);
        paper[u] = 1;
        for (v = 1; v <= n; v++)
        {
            if (!paper[v] || e[u][v] < INF)
            {
                if (dis[v] > e[u][v])
                    dis[v] = e[u][v];
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];
        init();
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                e[i][j] = e[j][i] = dist(i, j);
        Prim();
    }
    return 0;
}
