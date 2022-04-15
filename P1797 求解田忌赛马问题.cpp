/*
问题描述

两千多年前的战国时期，齐威王与大将田忌赛马。双方约定每人各出 300 匹马，并且在上、中、下 3 个等级中各选一匹进行比赛，由于齐威王每个等级的马都比田忌的马略强，比赛的结果可想而知。现在双方各 n 匹马，依次派出一匹马进行比赛，每一轮获胜的一方将从输的一方得到 200 银币，平局则不用出钱，田忌已知所有马的速度值并可以安排出场顺序，问他如何安排比赛获得的银币最多？
Tip: 本题为单组输入

输入描述

第 1 行，一个正整数 n(n≤100000)，表示马的数量； 后两行分别是 n 个整数，表示田忌和齐威王的马的速度值。

输出描述
每个测试用例输出一行，表示田忌获得的最多银币数。

样例输入

3
92 83 71
95 87 74

样例输出

200
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100002];
int b[100002];
int ans;

void solve()
{
    sort(a, a + n);
    sort(b, b + n);
    ans = 0;
    int La = 0, Lb = 0;
    int Ra = n - 1, Rb = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (a[Ra] > b[Rb])
        {
            ans += 200;
            Ra--;
            Rb--;
            continue;
        }
        if (a[La] > b[Lb])
        {
            ans += 200;
            La++;
            Lb++;
            continue;
        }
        if (a[La] < b[Rb])
        {
            ans -= 200;
            La++;
            Rb--;
        }
        else if (a[La] == b[Rb])
        {
            La++;
            Rb--;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    solve();
    cout << ans << endl;
    return 0;
}