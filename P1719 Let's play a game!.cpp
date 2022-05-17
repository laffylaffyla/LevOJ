/* 题目描述

现有一包含n 个数的序列A1,A2,A3,...,An，给定一个定值k.
每次我们可以选择数列中一个下标为 2 的次幂的元素（如A1,A2,A4,A8...)将其删除出数列（删除后，其后的所有元素会自动前移一格）。
问最少进行多少次操作，能将序列中所有值为k的元素删除？

输入描述

第一行两个整数n,k

第二行
n 个整数，A1,A2,A3,...,An

输出描述

第一行一个整数，为最少操作次数。

样例输入 1

5 2
1 2 4 2 5
样例输出 1

2
样例输入 2

5 2
1 2 2 2 2
样例输出 2

4 */
#include <iostream>
#include <algorithm>
#define MAXN 300002

using namespace std;

int n, k, a;
int ans = 0, flag = 0, t = 1, m = 0;
int arr[MAXN];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (i > t)
        {
            t = t * 2;
        }
        if (a == k)
        {
            if (t > i)
            {
                t = t / 2;
            }
            flag++;
            arr[flag] = i - t - flag + 1;
            m = m > arr[flag] ? m : arr[flag];
        }
    }
    cout << flag + m << endl;
    return 0;
}