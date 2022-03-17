#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		if (((a + b) <= c || (b + c) <= a || (a + c) <= b))
		{
			printf("not a triangle\n");
		}
		else
		{
			if (a == b && b == c && a == c)
			{
				printf("regular triangle\n");
			}
			else
			{
				if (a == b || b == c || a == c)
				{
					printf("isosceles triangle\n");
				}
				else
				{
					if ((a * a + b * b == c * c) || (c * c + b * b == a * a) || (a * a + c * c == b * b))
						printf("right triangle\n");
					else
						printf("triangle\n");
				}
			}
		}
	}
	return 0;
}