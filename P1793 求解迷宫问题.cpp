/*
问题描述

有一 8×8 的迷宫图，其中 O 表示通路方块，X 表示障碍方块。假设入口位置为 (0,0)，出口为右下角方块位置 (7,7)。设计一个程序求指定入口到出口的一条迷宫路径。

输入描述
8 行，每行 8 个字符表示迷宫。
输入保证至少存在一条合法路径。

输出描述
8 行，每行 8 个字符，空格表示所选路径。

样例输入

OXXXXXXX
OOOOOXXX
XOXXOOOX
XOXXOXXO
XOXXXXXX
XOXXOOOX
XOOOOXOO
XXXXXXXO

样例输出

 XXXXXXX
  OOOXXX
X XXOOOX
X XXOXXO
X XXXXXX
X XX   X
X    X
XXXXXXX
*/

/* TLEEEEEEEEEEEEEE
#include <iostream>

using namespace std;

char Maze[8][8];

int H[4] = {0, 1, 0, -1};
int V[4] = {-1, 0, 1, 0};

void DFS(int x, int y)
{
    if (x == 7 && y == 7)
    {
        Maze[7][7] = ' ';
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << Maze[i][j];
            }
            cout << endl;
        }
        return;
    }
    else
    {
        for (int k = 0; k < 4; k++)
            if (x >= 0 && y >= 0 && x < 8 && y < 8 && Maze[x][y] == 'O')
            {
                Maze[x][y] = ' ';
                DFS(x + V[k], y + H[k]);
                Maze[x][y] = 'O';
            }
    }
}

int main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> Maze[i][j];
        }
    }
    DFS(0, 0);
    return 0;
}
*/

#include <iostream>

using namespace std;

char Maze[8][8];

int h[4] = {0, 1, 0, -1}; 
int v[4] = {-1, 0, 1, 0}; 

struct Position
{
    int x, y; 
    int pre;  
};

Position queue[129];      
int front = -1, rear = -1; 

void displayAns(int front)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (Maze[i][j] == '*')
                Maze[i][j] = 'O';
        }
    int k = front;
    while (k != -1)
    {
        Maze[queue[k].x][queue[k].y] = ' ';
        k = queue[k].pre;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << Maze[i][j];
        cout << endl;
    }
}

void BFS(int x, int y)
{
    Position p, p1, p2;
    p.x = x, p.y = y;
    p.pre = -1;
    Maze[p.x][p.y] = '*'; 
    queue[++rear] = p; 
    while (front != rear)
    {
        p1 = queue[++front];
        if (p1.x == 7 && p1.y == 7)
        {
            displayAns(front);
            return;
        }
        for (int k = 0; k < 4; k++)
        {
            p2.x = p1.x + h[k];
            p2.y = p1.y + v[k];
            if (p2.x >= 0 && p2.y >= 0 && p2.y < 8 && p2.y < 8 && Maze[p2.x][p2.y] == 'O')
            {
                Maze[p2.x][p2.y] = '*';
                p2.pre = front;
                queue[++rear] = p2;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> Maze[i][j];
        }
    }
    BFS(0, 0);
    return 0;
}
