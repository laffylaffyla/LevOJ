#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a;
	while (scanf("%d", &a) != EOF)
	{
		int i;
		for (i = 2; i <= a;)
		{
			if (a % i == 0)
			{
				a = a / i;
				printf("%d ", i);
				i = 2;
			}
			else
			{
				i++;
			}
		}
		printf("\n");
	}
	return 0;
}