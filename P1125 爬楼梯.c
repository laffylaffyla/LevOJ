#define _CRT_SECURE_NO_WARNINGS
/*
题目描述
一个有 n 级台阶的楼梯，一步可以上 1 级，也可以上 2 级，计算走到楼上有多少种不同的走法

输入描述
一个正整数 n , 占一行 (n<=35)

输出描述
一个整数表示方案数，数据保证结果在 int 范围内。

样例输入

20
33

样例输出

10946
5702887
*/

#include<stdio.h>

int main()
{
    unsigned long count(int n);
    int n;
    unsigned long m;
    while (scanf("%d", &n) != EOF)
    {
        m = count(n);
        printf("%lu\n", m);
    }
    return 0;
}
unsigned long count(int n)
{
    unsigned long f;
    if (n == 1)
        f = 1;
    else if (n == 2)
        f = 2;
    else
        f = count(n - 1) + count(n - 2);
    return(f);
}