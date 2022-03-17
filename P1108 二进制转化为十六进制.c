#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int convertBinaryToDecimal(long long n);

int main()
{
    long long n;
    while (scanf("%lld", &n) != EOF)
    {
        if (n == 0)
            exit(0);
        else
            printf("%X\n", convertBinaryToDecimal(n));
    }
    return 0;
}

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n != 0)
    {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}