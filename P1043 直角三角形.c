#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double a, b, c;
	while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
	{
		if ((a * a + b * b == c * c) || (c * c + b * b == a * a) || (a * a + c * c == b * b))
		    printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}