#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int m, k, n, i, t, a;
	double p = 0;
	int s = 0, q = 0;
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &k, &n);
		for (t = 0; t < k; t++)
		{
			scanf("%d", &a);
			if (a > n)
			{
				s = s + a;
				q = q + 1;
			}
		}
		if (q == 0)
		{
			printf("-1\n");
			p = 0;
			s = 0;
			q = 0;
		}
		else
		{
			p = (double)s / q;
			printf("%.2f\n", p);
			p = 0;
			s = 0;
			q = 0;
		}
	}
	return 0;
}