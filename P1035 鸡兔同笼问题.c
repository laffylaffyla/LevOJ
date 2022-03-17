#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double m, n;
	while (scanf("%lf %lf", &m, &n) != EOF)
	{
		double a, b;
		a = 2 * m - n / 2;
		b = n / 2 - m;
		if ((a >= 0 && b >= 0) && ((int)a == a && (int)b == b))
		{
			a = a;
			b = b;
		}
		else
		{
			a = -1;
			b = -1;
		}
		printf("%d %d\n", (int)a, (int)b);
	}
	return 0;
}