/*
问题描述
在 m 行 n 列的棋盘上有一个中国象棋中的马，马走日字且只能向右走。
请找到可行路径的条数，使得马从棋盘的左下角 (1,1) 走到右上角 (m,n)。
Tip 1: 本题为单组输入。
Tip 2: 马向右走指从 (X,Y) 走到 (X+2, Y+1) 或 (X+1, Y+2) 位置

输入描述
一行，两个正整数 n m。

输出描述
一行，表示相应的路径条数。

样例输入

4 4

样例输出

2
*/

#include <iostream>

using namespace std;

static int chessBoard[102][102] = {0};
static int ans = 0;

const int dx[4] = {2, 1, -1, -2};
const int dy[4] = {1, 2, 2, 1};

void umaJump(int x, int y, int destx, int desty)
{
    if (x >= 0 && x < destx && y >= 0 && y < desty && chessBoard[x][y] == 0)
    {
        if (x == destx - 1 && y == desty - 1)
        {
            ans++;
            return;
        }
        chessBoard[x][y] = 1;
        int i;
        for (i = 0; i < 2; ++i)
        {
            umaJump(x + dx[i], y + dy[i], destx, desty);
        }
        chessBoard[x][y] = 0;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    umaJump(0, 0, m, n);
    cout << ans << endl;
    return 0;
}
