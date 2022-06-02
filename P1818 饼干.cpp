/* 题目描述

ly 在战场凹分，没吃午饭，饥肠辘辘的他从文具盒里翻出了一袋饼干......

这袋饼干有 n 块，分别称作第 1,2...n 块，第 i 块饼干能提供 w [i] 的饱腹感.

有强迫症的 ly 必须从第 1 块开始吃，然后第 2 块... 直到总饱腹感达到（大于或等于）s 时即停止.

众所周知，万事万物都会随着多种因素的变化而变化，当然 ly 的饱腹感上限 s 也不例外

于是 ly 会询问你 q 次：当他的饱腹感上限为 s [i] 时，他需要吃多少块饼干

输入描述

对于每个测试点，有三行输入

第一行，输入两个正整数 n, q (n, q <= 20'0000),n 表示饼干的数量，q 表示询问的次数.

第二行，输入 n 个正整数 w [i]，(w [i] <= 1000) 表示第 i 块饼干的饱腹感.

第三行，输入 p 个正整数 s [i], (s [i] <= 2'0000'0000), 表示 ly 第 i 次询问时的饱腹感上限.

输出描述

仅一行：q 个正整数，第 i 个数表示 ly 第 i 次询问时需要吃的饼干数.

样例输入

5 3
3 7 9 5 4
5 2 19
样例输出

2 1 3
提示 / 说明

样例解释：

s [1] = 5, 当吃完第 1,2 块后总饱腹感为 10, 即停止

s [2] = 2, 当吃完第 1 块后总饱腹感为 3, 即停止

s [1] = 19, 当吃完第 1,2,3 块后总饱腹感为 19, 即停止

数据范围：n,q ≤200000, w[i] ≤1000, s[i] ≤200000000. 保证：任意 s [i] 小于所有 w [i] 之和. */
#include <iostream>

using namespace std;

const int MAXN = 200002;
int w[MAXN] = {0}, s[MAXN] = {0};
int n, q;

/* inline int search(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (w[i] >= x)
            return i;
    }
} */

inline int search(int x)
{
    int l = 0;
    int r = n;
    while (l != r)
    {
        int mid = (l + r) / 2;
        if (w[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        w[i] += w[i - 1];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> s[i];
    }
    cout << search(s[1]);
    for (int i = 2; i <= q; i++)
        cout << " " << search(s[i]);
}