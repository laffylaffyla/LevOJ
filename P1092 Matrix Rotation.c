#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	long long k, s;
	int n, a[11][11], i, j, t;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
		scanf("%lld", &k); k++;
		t = k % 4;
		k /= 4;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				s = a[i][j] + a[n - j - 1][i] + a[n - i - 1][n - j - 1]
					+ a[j][n - i - 1];
				s *= k;
				switch (t)
				{
				case 3:
					s += a[n - i - 1][n - j - 1];
				case 2:
					s += a[n - j - 1][i];
				case 1:
					s += a[i][j];
				}
				printf("%lld ", s);
			}
			printf("\n");
		}
	}
	return 0;
}