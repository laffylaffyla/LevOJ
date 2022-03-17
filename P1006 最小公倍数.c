#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, d;
	int i, t, p;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%lf %lf", &a, &b);
		if (a > b)
		{
			d = a;
			a = b;
			b = d;
		}
		else
		{
			a = a;
			b = b;
		}
		c = b / a;
		if ((int)c == c)
		{
			printf("%d\n", (int)b);
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
			p = (int)a * (int)b / m;
			printf("%d\n", p);
		}
	}
	return 0;
}