/*
题目描述
在一个非降序列序列中与给定值 t 最接近的元素

输入描述
第一行包含一个整数 n，为非降序列长度 (1<=n<=100 000)
第 2 行包含 n 个整数，为非降序列的各个元素， 所有元素的大小均在 0~1 000 000 000 范围内。
第 3 行包含一个整数 m， 为要询问的给定值的个数 (1<=m<=10 000)。接下来 m 行，每行一个整数， 为要询问最接近元素的给定值，所有给定值的大小均在 0~1 000 000 000 范围内。

输出描述
输出共 m 行，每行一个整数，为最接近相应给定值的元素值，并保持输入顺序。若有多个元素值满足条件，输出最小的一个。

输入样例

3
2 5 8
2
10
5

输出样例

8
5
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int m, n, t, l, r, mid, arr[100001];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> m;
    while (m--)
    {
        cin >> t;
        l = 1;
        r = n;
        while (l < r - 1)
        {
            mid = (l + r) / 2;
            if (arr[mid] > t)
                r = mid;
            else
                l = mid;
        }
        if (abs(arr[l] - t) <= abs(arr[r] - t))
            cout << arr[l] << endl;
        else
            cout << arr[r] << endl;
    }
    return 0;
}
