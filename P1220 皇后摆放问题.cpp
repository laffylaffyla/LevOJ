/*
题目描述
国际象棋的棋盘可以看做是一个 8 × 8 的矩阵，上面每一个格子仅能放一枚棋子，现在给出一个 8 × 8 的由 0 和 1 组成的矩阵，代表象棋棋盘，1 代表当前位置放置了一个皇后，0 则代表什么都没有放，上面有 n（n 为小于 8 的正整数）个位置已经放上了皇后棋子（相互之间不冲突，合理摆放），现在另外给你 8 - n 个皇后，问你有多少合理的摆法。

输入描述
一个 8 × 8 的由 0 和 1 组成的矩阵。

输出描述
一个整数，为摆放的种类数。

样例输入

1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
样例输出

4
*/

#include <iostream>

using namespace std;

int chessBoard[9][9];
bool constQueen[9] = {false};

bool isAvailable(int m, int n)
{
    for (int i = 0; i < 8; i++)
    {
        if (i != m && chessBoard[n][i])
            return false;
        if (i != n && chessBoard[i][m])
            return false;
    }
    for (int i = 1; n - i >= 0 && m - i >= 0; i++)
        if (chessBoard[n - i][m - i])
            return false;
    for (int i = 1; n + i < 8 && m - i >= 0; i++)
        if (chessBoard[n + i][m - i])
            return false;
    for (int i = 1; n - i >= 0 && m + i < 8; i++)
        if (chessBoard[n - i][m + i])
            return false;
    for (int i = 1; n + i < 8 && m + i < 8; i++)
        if (chessBoard[n + i][m + i])
            return false;
    return true;
}

int DFS(int n)
{
    if (n == 8)
        return 1;
    if (constQueen[n])
        return DFS(n + 1);
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        if (isAvailable(i, n))
        {
            chessBoard[n][i] = 1;
            result += DFS(n + 1);
            chessBoard[n][i] = 0;
        }
    }
    return result;
}

int main()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            cin >> chessBoard[i][j];
            if (chessBoard[i][j])
                constQueen[i] = true;
        }
    cout << DFS(0);
    return 0;
}
