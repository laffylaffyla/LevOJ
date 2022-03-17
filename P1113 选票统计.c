#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a[1001] = { 0 };
	int x, i;
	scanf("%d", &x);
	while (x != -1)
	{
		a[x]++;
		scanf("%d", &x);
	}
	for (i = 1; i <= 1000; i++)
	{
		if (a[i] > 0)
		{
			printf("%d %d\n", i, a[i]);
		}
	}
	return 0;
}