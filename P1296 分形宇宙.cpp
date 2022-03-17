/*
魔法世界的科学家分形宇宙论，即宇宙是一个基本微粒，构成宇宙的无数个微粒又会有其他的小宇宙。分形定义如下：

1 度的分形为：

X
2 度的分形为：

X X
 X
X X
如果 B (n-1) 表示 n-1 度的分形，则 n 度的分形递归定义如下：

B(n-1) B(n-1)
   B(n-1)
B(n-1) B(n-1)
要求给定分形的度，输出相应的分形图。

输入描述
多组输入，每组输入一个正整数 n

输出描述
对应于每组数，输出相应的分形图，并用一个 “-” 分隔

样例输入
1
2

样例输出
X
-
X X
 X
X X
-
*/

#include<iostream>
#include<cmath>

using namespace std;

char martix[3000][3000];

void fractal(int, int, int);

int main()
{
	int n;
	while (cin >> n)
	{
		int size = pow(3.0, n - 1);
		for (int i = 0; i <= size; i++)
			for (int j = 0; j <= size; j++)
				martix[i][j] = ' ';
		fractal(n, 1, 1);
		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= size; j++)
				cout << martix[i][j];
			cout << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}

void fractal(int n, int x, int y)
{
	if (n == 1)
	{
		martix[x][y] = 'X';
	}
	else
	{
		int size = pow(3.0, n - 2);
		fractal(n - 1, x, y);
		fractal(n - 1, x, y + 2 * size);
		fractal(n - 1, x + size, y + size); 
		fractal(n - 1, x + 2 * size, y);
		fractal(n - 1, x + 2 * size, y + 2 * size);
	}
	return;
}