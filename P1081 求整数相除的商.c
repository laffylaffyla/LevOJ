#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	long long a, b;
	while (scanf("%lld %lld", &a, &b) != EOF)
	{
		printf("%d\n", a / b);
	}
	return 0;
}