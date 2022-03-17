#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, s;
	while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
	{
		if (((a + b) <= c || (b + c) <= a || (a + c) <= b))
		{
			s = -1;
			printf("%d\n", (int)s);
		}
		else
		{
			double p;
			p = (a + b + c) / 2;
			s = sqrt(p * (p - a) * (p - b) * (p - c));
			printf("%.2f\n", s);
		}
	}
	return 0;
}