#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 1000

int main()
{
	int flag[MAX], N, i, value, count = 0;
	memset(flag, 0, sizeof(flag));
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &value);
		flag[abs(value)]++;
		if (flag[abs(value)] == 2)
			count++;
	}
	printf("%d", count);
	return 0;
}