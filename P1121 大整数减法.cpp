/*
题目描述
给出两个 200 位以内的正数，算出第一个数减第二个数的值（结果为正）。

输入描述
每组测试数据包括两行，第一行为被减数，第二行为减数。

输出描述
每组测试数据输出一行，为所求两个整数之差。

样例输入
987
654

样例输出
333
*/

#include <iostream>
#include <string>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int m[500], n[500], res[500];

int main()
{
    string a, b;
    int l1, l2, maxl, i;
    while (cin >> a >> b)
    {
        l1 = a.size();
        l2 = b.size();
        maxl = max(l1, l2);
        for (i = 0; i < l1; i++)
            m[l1 - i - 1] = a[i] - '0';
        for (i = 0; i < l2; i++)
            n[l2 - i - 1] = b[i] - '0';
        for (i = 0; i < maxl; i++)
        {
            if (m[i] < n[i])
            {
                m[i + 1]--;
                m[i] += 10;
            }
            res[i] = m[i] - n[i];
        }
        for (i = maxl - 1; i >= 0; i--)
        {
            if (res[i] == 0 && maxl > 1)
                maxl--;
            else
                break;
        }
        for (i = maxl - 1; i >= 0; i--)
            cout << res[i];
        cout << endl;
        memset(m, '\0', sizeof(m));
        memset(n, '\0', sizeof(n));
        memset(res, '\0', sizeof(res));
    }
    return 0;
}