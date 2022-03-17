#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n, k, i, j;
	int a[101];
	scanf("%d", &n);
	scanf("%d", &k);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	k = k % n;
	for (i = 0; i < k; i++)
	{
		int temp;
		temp = a[0];
		for (j = 0; j < n - 1; j++)
			a[j] = a[j + 1];
		a[n - 1] = temp;
	}
	for (i = 0; i < n; i++)
	{
		if(i)
			printf(" ");
		printf("%d", a[i]);
	}
}