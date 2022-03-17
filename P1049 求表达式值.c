#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a;
	double x, y, s;
	while (scanf("%d %lf %lf", &a, &x, &y) != EOF)
	{
		s = x + a % 3 * (int)(x + y) % 2 / 4;
		printf("%f\n", s);
	}
	return 0;
}