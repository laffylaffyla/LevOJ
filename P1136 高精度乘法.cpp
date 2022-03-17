/*
题目描述
给出两个长度小于 100 位的正整数，求其乘积。

输入描述
两行，一行一个数。

输出描述
一行，为所求乘积。

样例输入
1937
2931

样例输出
5677347
*/

#include <iostream>
#include <string>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int m[101], n[101], res[10201];

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
        for (int i = 0; i < l2; i++)
            for (int j = 0; j < l1; j++)
            {
                res[i + j] += m[j] * n[i];
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        maxl = l1 + l2;
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