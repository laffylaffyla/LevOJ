/*
题目描述
在一个划分成网格的操场上，n 个士兵散乱地站在网格点上。网格点用整数坐标 (x,y) 表示。士兵们可以沿网格边往上、下、左、右移动一步，但在同一时刻任一网格点上只能有一名士兵。按照军官的命令，士兵们要整齐地列成一个水平队列，即排列成 (x,y),(x+1,y),…,(x+n-1,y)。如何选择 x 和 y 的值才能使士兵们以最少的总移动步数排成一行。编程计算使所有士兵排成一行需要的最少移动步数。

输入描述
第 1 行是士兵数 n，1≤n≤10000。接下来 n 行是士兵的初始位置，每行有 2 个整数 x 和 y，-10000≤x，y≤10000。

输出描述
一个数据，即士兵排成一行需要的最少移动步数。

样例输入
5
1  2
2  2
1  3
3  -2
3  3

样例输出
8
*/

#include<iostream>
#include<algorithm>

using namespace std;

int x[10500], y[10500];

int main()
{
    int n, x1, y1, ans = 0;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        sort(x, x + n);
        sort(y, y + n);
        for (int i = 0; i < n; i++)
        {
            x[i] -= i;
        }
        sort(x, x + n);
        x1 = x[(n - 1) / 2];
        y1 = y[(n - 1) / 2];
        for (int i = 0; i < n; i++)
        {
            ans += abs(x[i] - x1);
            ans += abs(y[i] - y1);
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}