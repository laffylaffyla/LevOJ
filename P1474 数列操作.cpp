/* 题目描述

给定一个由 n 个正整数组成的数列，对数列进行一次操作：去除其中两项 a、b，然后添加一项 a×b+1。每操作一次数列减少一项，经 n−1 次操作后该数列只剩一个数。试求在 n-1 次操作后最后得数的最大值。

输入描述

多组输入，每组两行，第一行输入正整数 n，第二行输入 n 个正整数 n<20

输出描述

对每组输入，输出最后剩下的一个

样例输入

6
8 9 3 6 5 4

样例输出

29493 */

#include <iostream>
#include <algorithm>

using namespace std;

long long n, x;
long long // SB
    arr[22];

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr[i] = x;
        }
        while (n != 1)
        {
            sort(arr, arr + n);
            arr[0] = arr[0] * arr[1] + 1;
            n--;
            for (int i = 1; i < n; i++)
            {
                arr[i] = arr[i + 1];
            }
        }
        cout << arr[0] << endl;
    }
    return 0;
}