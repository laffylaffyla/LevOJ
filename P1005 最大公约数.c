#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double a, b, c, d;
	int i, t;
	scanf("%d", &t);
	for (i=1;i<=t;i++)
	{
		scanf("%lf %lf", &a, &b);
		if (a > b)
		{
			d = a;
			a = b;
			b = d;
		}
		c = b/a;
		if ((int)c == c)
		{
			printf("%d\n", (int)a);
		}
		else
		{
			int m, n;
			m = (int)a;
			n = (int)b;
			int r = 1;
			while (r != 0)
			{
				r = m % n;
				m = n;
				n = r;
			}
			printf("%d\n", m);
		}
	}
	return 0;
}