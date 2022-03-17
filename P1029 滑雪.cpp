/*
题目描述

小明喜欢滑雪，为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。小明想知道在一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子:
1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为 24-17-16-1 . 当然 25-24-23-...-3-2-1 更长。事实上，这是最长的一条.

输入描述
输入的第一行表示区域的行数 R 和列数 C (1≤R,C≤100). 下面是 R 行，每行有 C 个整数，代表高度h, 0≤h≤10000.

输出描述
输出最长区域的长度.

样例输入

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

样例输出

25
*/

#include <iostream>
#include <cstring>

using namespace std;

int altitude[102][102];
int longestRoute[102][102];
int m, n;

int count(int i, int j)
{
    int max = 0;
    if (longestRoute[i][j] > 0)
        return longestRoute[i][j];
    if (i - 1 >= 0 && altitude[i][j] > altitude[i - 1][j] && max < count(i - 1, j))
        max = count(i - 1, j);
    if (j - 1 >= 0 && altitude[i][j] > altitude[i][j - 1] && max < count(i, j - 1))
        max = count(i, j - 1);
    if (i + 1 < m && altitude[i][j] > altitude[i + 1][j] && max < count(i + 1, j))
        max = count(i + 1, j);
    if (j + 1 < n && altitude[i][j] > altitude[i][j + 1] && max < count(i, j + 1))
        max = count(i, j + 1);
    longestRoute[i][j] = max + 1;
    return longestRoute[i][j];
}

int main()
{
    while (cin >> m >> n)
    {
        int maxResult = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> altitude[i][j];
                longestRoute[i][j] = 0;
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                longestRoute[i][j] = count(i, j);
                if (maxResult < longestRoute[i][j])
                    maxResult = longestRoute[i][j];
            }
        cout << maxResult << endl;
    }
    return 0;
}
