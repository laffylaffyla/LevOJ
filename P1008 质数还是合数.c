#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
    int n, i;
    while (scanf("%d", &n) != EOF)
    {
        int t = 0;
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
                t = 1;
        }
        if (t == 1)
            printf("No\n");
        if (t == 0)
            printf("Yes\n");
    }
    return 0;
}