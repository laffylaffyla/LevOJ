/*
题目描述
给出两个 200 位以内的正整数，求其和。

输入描述
多组测试数据。每组测试数据包括两行，每行一个数。

输出描述
每组测试输出一行，为所求两个整数之和。

样例输入
123
456

样例输出
579
*/

#include <iostream>
#include <string>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int m[500], n[500];

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
            m[i] = m[i] + n[i];
            m[i + 1] += m[i] / 10;
            m[i] %= 10;
        }
        if (m[maxl] == 1)
            maxl++;
        for (i = maxl - 1; i >= 0; i--)
            cout << m[i];
        cout << endl;
        memset(m, '\0', sizeof(m));
        memset(n, '\0', sizeof(n));
    }
    return 0;
}