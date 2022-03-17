#include <stdio.h>

int main()
{
    char a[100];
    int i;
    gets(a);
    for (i = 0; a[i] != '\0'; i++)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;
    puts(a);
    return 0;
}