#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include<NUIST.h>
//typedef main mian

int same_factory(int, int);

int main()
{
	int k, i, n, m;
	int a = 0;
	scanf("%d", &k);
	for (i = 0; i < k; i++)
	{
		scanf("%d", &n);
		scanf("%d", &m);
		a = same_factory(n, m);
		if (a == m)
			a = -1;
		printf("%d\n", a);
	}
	return 0;
}

int same_factory(int n, int m)
{
	int a, i, min, temp;
	min = n < m ? n : m;
	for (i = 1; i < min; i++)
	{
		temp = m - i;
		if (n % i == 0 && n % temp == 0)
			break;
	}
	return i;
}