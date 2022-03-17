#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int gcd(double, double);

int main()
{
	double a, b, c, d, p, q;
	int i, t;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%lf %lf %lf", &a, &b, &c);
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
		if (b > c)
		{
			d = b;
			b = c;
			c = d;
		}
		else
		{
			b = b;
			c = c;
		}
		p = gcd(a, b);
		q = gcd(p, c);
		printf("%d\n", (int)q);
	}
	return 0;
}
int gcd(double x, double y)
{
	double s;
	int a1;
	s = y / x;
	if ((int)s == s)
	{
		a1 = (int)x;
	}
	else
	{
		int m, n;
		m = (int)x;
		n = (int)y;
		int r = 1;
		while (r != 0)
		{
			r = m % n;
			m = n;
			n = r;
		}
		a1 = m;
	}
	return a1;
}