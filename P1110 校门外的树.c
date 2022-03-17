#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int a[10002];

int main()
{
	int l, m, t1, t2, i, count;
	while (scanf("%d %d", &l, &m)!=EOF)
	{
		for (i = 0; i <= l; i++)
			a[i] = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &t1, &t2);
			for ( t1!=0; t1 <= t2; t1++)
				a[t1] = t1;
		}
		for (i = count = 0; i <= l; i++)
			if (!a[i])
				count++;
		printf("%d\n", count);
	}
	return 0;
}