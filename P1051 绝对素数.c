#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int pdss(int);
int hws(int);

int main()
{
	int i, t;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		int f, h1, h2, m;
		scanf("%d", &f);
		h1 = pdss(f);
		h2 = pdss(hws(f));
		if (((h1 == 0) && (h2 == 0)))
			m = 1;
		else
			m = 0;
		printf("%d\n", m);
	}
	return 0;
}

int pdss(int n)
{
	int i;
	int t = 0;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
			t = 1;
	}
	return t;
}

int hws(int n)
{
	int s = 0;
	while (n)
	{
		s = s * 10 + n % 10;
		n = n / 10;
	}
	return s;
}