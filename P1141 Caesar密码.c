#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
const char a[28] = { 'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U' };
int main()
{
	char s[15], c;
	while (scanf("%s", s) != EOF)
	{
		if (strcmp(s, "ENDOFINPUT") == 0)
			break;
		scanf("%*c", &c);
		scanf("%c", &c);
		do
		{
			if (c >= 'A' && c <= 'Z')
				printf("%c", a[c - 'A']);
			else
				printf("%c", c);
			scanf("%c", &c);
		} while (c - '\n');
		printf("\n");
		scanf("%*s");
	}
	return 0;
}