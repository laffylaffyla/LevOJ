#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void print_reverse(char*);

int main()
{
    int n, i;
    char s[1001];
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        gets(s);
        print_reverse(&s);
        printf("\n");
    }
    return 0;
}

void print_reverse(char* s)
{
    size_t len = strlen(s);
    char* t = s + len - 1;
    while (t >= s)
    {
        printf("%c", *t);
        t--;
    }
}