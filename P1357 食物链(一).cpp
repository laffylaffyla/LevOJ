/* 题目描述

数一数，在这个食物网中最长的食物链包含的物种数是 ( )

......

现在给你 n 个物种和 m 条能量流动关系，求其中的食物链条数。

物种的名称为从 1 到 n 编号，m 条能量流动关系形如

a1 b1

a2 b2

a3 b3

……

am−1 bm−1

am bm

其中 ai bi 表示能量从物种 ai 流向物种 bi，即 ai 和 bi 之间存在捕食关系，且 ai 是被捕食者， bi 是捕食者。一条食物链是从顶到底的，即从能量流向的起点到终点。如图中的草－＞兔－＞狐就是一条食物链，而草－＞兔则不是。

一条食物链至少包含两种生物。

输入描述

多组输入，每组第一行两个正整数 n 和 m。0 < n, m <= 1000

接下来 m 行每行两个整数 ai bi 表示 m 个捕食关系。

(数据保证输入数据符号合生物学特点，且不会有重复的能量流动关系出现)

输出描述

一个整数即食物网中的最长的食物链包含的生物数。

样例输入

10 16
1 2
1 4
1 10
2 3
2 5
4 3
4 5
4 8
6 8
7 6
7 9
8 5
9 8
10 6
10 7
10 9

样例输出

6 */
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1002;
int n, m, ans = 0;
vector<int> ani[MAXN];

void search(int n, int cnt)
{
    cnt++;
    ans = ans > cnt ? ans : cnt;
    if (!ani[n].empty())
    {
        for (int i = 0; i < ani[n].size(); i++)
        {
            search(ani[n][i], cnt);
        }
    }
}

int main()
{
    cin >> n >> m;
    ans = 0;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        ani[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ani[i].empty())
        {
            search(i, 0);
        }
    }
    cout << ans << endl;
    /* while (cin >> n >> m)
    {
        ans = 0;
        int a, b;
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            ani[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!ani[i].empty())
            {
                search(i, 0);
            }
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++)
        {
            ani[i].clear();
        }
    } */
    return 0;
}