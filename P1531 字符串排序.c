#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char str[100][100];
    for (int i = 0; i < n; i++)
        gets(str[i]);
    char tmp[100];
    //简单冒泡排序
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(str[j], str[j + 1]) > 0) //   相当于前面的字符串减去后面的,具体见strcmp函数
            {
                strcpy(tmp, str[j]);    // 使用函数strcpy
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], tmp);
            }
        }
    for (int i = 0; i < n; i++)
        puts(str[i]);
    return 0;
}
