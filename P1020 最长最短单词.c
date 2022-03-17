#include<stdio.h>

int main()
{
    char a[500];
    int i = 0, j = 0, b = 0, m = 0, n = 0, d = 0;
    gets(a);
    while (a[i] != '\0')
    {
        while (a[i] != ' ' && a[i] != '\0')
        {
            j++;
            i++;
        }
        if (j > b)
        {
            m = i - j;
            b = j;
        }
        if (j < d)
        {
            n = i - j;
            d = j;
        }
        while (a[i] == ' ')
            i++;
        j = 0;
    }
    while (a[m] != ' ' && a[m] != '\0')
    {
        printf("%c", a[m]);
        m++;
    }
    printf("\n");
    while (a[n] != ' ' && a[n] != '\0')
    {
        printf("%c", a[n]);
        n++;
    }
    printf("\n");
    return 0;
}