#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char a[80][30], team[30];
	int i, n;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < 80; i++)
			a[i][0] = 0;
		while (n--)
		{
			scanf("%*c");
			scanf("%[^0-9]", team);
			scanf("%d", &i);
			i -= 1947;
			strcpy(a[i], team);
		}
		for (i = 0; i < 80; i++)
			if (a[i][0])
				printf("%d %s\n", i + 1947, a[i]);
	}
	return 0;
}