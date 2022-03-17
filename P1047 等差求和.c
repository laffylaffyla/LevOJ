#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a, d, n, s;
	scanf("%d %d %d", &a, &d, &n);
	s = a * n + n * (n - 1) * d / 2;
	printf("%d", s);
	return 0;
}