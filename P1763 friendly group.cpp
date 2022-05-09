/* 题目描述
Professor Alex will organize students to attend an academic conference.

Alex 教授将要组织学生参加学术会议。

Alex has n excellent students, and he decides to select some of them (possibly none) to attend the conference. They form a group. Some pairs of them are friends.

Alex 有 n 个很好的的学生，他决定选一些（也可能不选）让他们去开会，他们组成了一个小组，有些学生两两是朋友。

The friendly value of the group is initially 0. For each couple of friends (x,y), if both of them attend the conference, the friendly value of the group will increase 1, and if only one of them attends the conference, the friendly value of the group will decrease 1. If num students attend the conference, the friendly value of the group will decrease num.

小组的 “友爱值” 初始是 0，对于每一对好朋友 (x,y)，如果他们都参加会议了，“友爱值” 就会增加 1，如果一对好朋友只有一个人去参加会议，友爱值就会减少 1。如果有 num 个学生参加了会议，友爱值会减少 num 。

Alex wants to manume the group more friendly. Please output the maximum friendly value of the group.

Alex 想让这个小组很有爱。请输出最大的友爱值是多少。

输入描述
The first line of the input gives the number of test cases, T (1≤T≤10^4). T test cases follow.

T 组数据。

For each test case, the first line contains two integers n (1≤n≤3×10^5) and m (1≤m≤10^6), where n is the number of students and m is the number of couples of friends.

n 个学生，m 个朋友。

Each of the following m lines contains two integers xi,yi(1≤xi,yi≤n,xi≠yi), representing student xi and student yi are friends. It guaranteed that unordered pairs (xi,yi) are distinct.

m 行， 每一行两个数字，代表两个人是朋友。

The sum of n in all test cases doesn't exceed 10^6, and the sum of m in all test cases doesn't exceed 2×10^6.

n 的总和不超过 1e6，m 的总和不超过 2e6。

输出描述
For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1), and y is the maximum friendly value of the group.
每个样例以 "Case #x: y" 的形式输出。

样例输入

2
4 5
1 2
1 3
1 4
2 3
3 4
2 1
1 2
样例输出

Case #1: 1
Case #2: 0 */

#include <iostream>

using namespace std;

const int MAXN = 3e5 + 10;
int t, n, m, num, ans;
int f[MAXN], a[MAXN], b[MAXN];

int getf(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = getf(f[x]);
}

int main()
{
    cin >> t;
    num = 0;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            f[i] = i;
            a[i] = 0;
            b[i] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            int t1, t2;
            cin >> t1 >> t2;
            int u = getf(t1);
            int v = getf(t2);
            if (u == v)
                a[u]++;
            else
            {
                f[v] = u;
                a[u] += a[v] + 1;
                b[u] += b[v];
            }
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == f[i] && a[i] - b[i] > 0)
                ans += a[i] - b[i];
        }
        cout << "Case #" << ++num << ": " << ans << endl;
    }
    return 0;
}
