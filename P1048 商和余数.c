#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a, b, c, d;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		c = a / b;
		d = a % b;
		printf("%d %d\n", c, d);
	}
	return 0;
}