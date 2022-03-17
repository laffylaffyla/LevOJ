#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

long long hanoi(int m)
{
	long long f;
	if (m == 1)
		f = 1;
	else
		f = 2 * hanoi(m - 1) + 1;
	return f;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%lld\n", hanoi(n));
	}
	return 0;
}