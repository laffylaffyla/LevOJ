#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i, n, s = 0, t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		s += t;
	}
	printf("%d", s);
	return 0;
}