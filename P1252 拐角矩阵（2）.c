#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n, i, t, m;
	int a[20] = { 0 };
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			a[i] = n - i;
		}
		for (t = 0; t < n; t++)
		{
			for (i = 0; i < n; i++)
			{
				printf("%d ", a[i]);
			}
			printf("\n");
			for (m = 0; m <= t; m++)
			{
				a[m] = a[m] - 1;
			}
		}
	}
	return 0;
}