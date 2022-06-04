/* 题目描述

众所周知，三水喜欢吃莲蓉蛋黄馅的月饼。这天，三水的好朋友送给三水一箱礼物，里面有 n 个月饼，每个月饼都有三个属性：进食时间 t，过期时间 b，快乐值 h。

因为每个月饼大小不一，所以吃每个月饼花费的时间都不同，对于月饼 i , 需要 ti 的时间才能吃完。每个月饼都有其保质期，月饼 i 会在 bi 时刻过期。此外，每个月饼的馅也不尽相同，吃完月饼 i 能给三水带来 hi 的快乐（莲蓉蛋黄馅当然是满分）。

需要说明的是，三水不会吃过期的月饼，更不希望月饼在被吃的过程中过期。但是如果这个月饼恰好在被吃完的时刻过期，那么这个月饼仍然可以给三水带来快乐。

三水是一个环保主义者，他不希望 看到 任何一个月饼过期。所以三水可以在任意时刻结束进餐，并且立刻离开餐厅（离开餐厅之后三水就不会回来了）。在他结束进餐时，三水必须吃完所有在 当前时刻及其之前 过期的月饼。这样，三水就不会 看到 还没被吃掉的月饼过期了。因为三水下午还有课，所以最多花费 T 时间进餐。现在三水想知道，在满足上述条件的情况下，最多能得到多少快乐。

三水当然知道该怎么算啦，但还是希望你帮他算一算。

输入描述

第一行输入两个整数 n (1≤n≤10^3) , T (1≤T≤10^4) , 其中 n 为月饼个数， T 表示三水不能晚于 T 时刻离开餐厅。

接下来 n 行，每行输入三个整数 ti,bi,hi (1≤ti,bi≤T,0≤hi≤10^9)，分别表示进食月饼需要花费的时间，月饼的过期时刻，以及吃完这个月饼能带来的快乐。

开始时的时刻为 0。

输出描述

一个正整数，表示三水最多能得到多少快乐。

样例输入

3 10
2 5 2
7 9 4
1 8 3
样例输出

5
样例说明

三水在 (0,2) 时间内吃掉了第一个月饼获得了 2 的快乐，然后在 (2,3) 时间吃掉了第三个月饼获得了 3 的快乐。然后他离开餐厅任由第二个月饼过期。 */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100002;

int n, t;
long long ans = 0;
long long dp[MAXN], pret[MAXN] = {0}, preh[MAXN] = {0};
bool check[MAXN];
struct Cake
{
    long long t, b, h;
} cake[MAXN];

bool cmp_b(Cake x, Cake y)
{
    return x.b < y.b;
}

void eat()
{
    for (int i = 1; i <= n; ++i)
    {
        preh[i] = preh[i - 1] + cake[i].h;
        pret[i] = pret[i - 1] + cake[i].t;
        check[i] = check[i - 1] && pret[i] <= cake[i].b && pret[i] <= t;
    }
    for (int i = n; i >= 0; --i)
    {
        for (int j = t; j >= cake[i + 1].t; --j)
        {
            dp[j] = max(dp[j], dp[j - cake[i + 1].t] + cake[i + 1].h);
        }
        if (check[i])
        {
            ans = max(ans, dp[min((long long)t, cake[i + 1].b - 1) - pret[i]] + preh[i]);
        }
    }
}

int main()
{

    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        cin >> cake[i].t >> cake[i].b >> cake[i].h;
    sort(cake + 1, cake + 1 + n, cmp_b);
    check[0] = true;
    eat();
    cout << ans << endl;
    return 0;
}
