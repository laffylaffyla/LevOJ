/*
题目描述
设有n 个正整数，将它们连成一排，组成一个最大的多位数。例如：输入n=3以及三个正整数 13,
312,343，则连成的最大数为 34331213

输入描述
第1行输入正整数个数n，下面n行输入n个整数

输出描述
一行，组成的最大整数

样例羭入

4
7
13
4
246

样例愉出

7424613
*/

/*
测试平台：https://www.nowcoder.com/questionTerminal/a6a656249f404eb498d16b2f8eaa2c60
通过全部用例
运行时间
5ms
占用内存
332KB
*/

//来自WSXNH TRUST

#include <stdio.h>
#include <math.h>
int num(int a)
{
    int i = 0;
    do
    {
        i++;
        a = a / 10;
    } while (a);
    return i;
}

int fun(int a, int b)
{
    int i = num(a), j = num(b);
    if (a * pow(10, j) + b < b * pow(10, i) + a)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    // int a[n];
    int *a;
    a = (int *)malloc(n * sizeof(int));
    int i, temp, j;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - 1 - j; i++)
        {
            if (fun(a[i], a[i + 1]))
            {
                temp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    free(a);
    return 0;
}