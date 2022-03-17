/*
设 x,y 为非负整数，试计算集合 M={(2^x)*(3^y),x>=0,y>=0} 的元素不大于指定整数 n 的个数，并求这些元素从小到大排序的第 m 项。

输入描述
多组输入，每组一行，输入 n 和 m，n 和 m 之间用一个空格分开

输出描述
对于每组输入，输出数列中不大于 n 的项数以及第 m 项的值，这两个数占两行。

样例输入：
10000000 100

样例输出：
190
93312
*/

#include<iostream>

using namespace std;

int a[10000];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int p, ans = 3;
        a[1] = 1;
        a[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            p = i;
            while (p % 2 == 0)
            {
                p = p / 2;
            }
            while (p % 3 == 0)
            {
                p = p / 3;
            }
            if (p == 1)
            {
                a[ans] = i;
                ans++;
            }
        }
        ans = ans - 1;
        cout << ans << endl;
        cout << a[m] << endl;
    }
}