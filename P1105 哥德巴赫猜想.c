#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int PN(int);

int main()
{
    int n;
	while (scanf("%d", &n) != EOF)
	{
		int i;
		for (i = 2; i <= n / 2; i++)
		{
			int x1 = i, x2 = n - i;
			int p1 = 1, p2 = 1;
			p1 = PN(x1);
			p2 = PN(x2);
			if (p1 == 1 && p2 == 1)
			{
				printf("%d+%d\n", x1, x2);
				break;
			}
		}
	}
	return 0;
}

int PN(int n)
{
	int i, p = 1;
	for (i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0)
		{
			p = 0;
		}
	}
	return p;
}