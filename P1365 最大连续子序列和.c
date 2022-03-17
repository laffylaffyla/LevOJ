#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	int n, i, max, s;
	int a[95001];
	memset(a, '\0', sizeof(a));
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		max = a[0];
		s = 0;
		for (i = 0; i < n; i++)
		{
			s += a[i];
			if (s > max)
				max = s;
			if (s < 0)
				s = 0;
		}
		printf("%d\n", max);
		memset(a, '\0', sizeof(a));
	}
	return 0;
}