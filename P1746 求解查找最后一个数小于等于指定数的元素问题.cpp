/*
题目描述
给定一定长度为 n 的单调递增的正整数序列，即序列中的每一个数都比前一个大，有 m 个询问，每次询问一个 x，问序列中最后一个小于等于 x 的数是什么？
n<=100000

输入描述
给定一个长度为 n 的单调递增的正整数序列，即序列中的每一个数都比前一个数大，有 m 个询问， 每次询问一个 x。

输出描述
输出共 m 行，表示序列中最后一个小于等于 x 的数都是多少。如果没有输出 - 1。

样例输入

5 3
1 2 3 4 6
5
1
3

样例输出

4
1
3
*/

#include <iostream>

using namespace std;

int main()
{
    int m, n, x;
    while (cin >> n >> m)
    {
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            int l = 0, r = n - 1, mid;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (arr[mid] <= x)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            int ans = -1;
            if (r >= 0)
            {
                ans = arr[r];
            }
            cout << ans << endl;
        }
        delete[] arr;
    }
    return 0;
}