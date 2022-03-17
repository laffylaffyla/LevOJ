#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int yyyy, mm;
	while (scanf("%d %d", &yyyy, &mm) != EOF)
	{
		if ((yyyy % 4 == 0) && (mm == 2))
		{
			printf("29\n");
		}
		else
		{
			if (mm == 2)
			{
				printf("28\n");
			}
			else
			{
				if ((mm == 1) || (mm == 3) || (mm == 5) || (mm == 7) || (mm == 8) || (mm == 10) || (mm == 12))
					printf("31\n");
				else
					printf("30\n");
			}
		}
	}
	return 0;
}