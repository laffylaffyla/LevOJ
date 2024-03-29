#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compar(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n, m, i, j, t, count;
	int a[1001], b[1001], c[1001];
	while (scanf("%d", &n)!=EOF)
	{
		memset(a, 0, 1001 * sizeof(int));
		memset(b, 0, 1001 * sizeof(int));
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), compar);
		scanf("%d", &m);
		for (i = 0; i < m; i++)
			scanf("%d", &b[i]);
		qsort(b, m, sizeof(int), compar);
		i = j = count = 0;
		while (i < n && j < m)
		{
			if (a[i] < b[j])
			{
				c[count] = i;
				count++;
				i++;
				continue;
			}
			if (a[i] > b[j])
			{
				j++;
				continue;
			}
			i++; j++;
		}
		if (j == m) for (; i < n; i++)
		{
			c[count] = i;
			count++;
		}
		for (i = 0; i < count; i++)
			printf("%d ", a[c[i]]);
		printf("\n");
	}
	return 0;
}