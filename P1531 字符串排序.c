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
    //��ð������
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(str[j], str[j + 1]) > 0) //   �൱��ǰ����ַ�����ȥ�����,�����strcmp����
            {
                strcpy(tmp, str[j]);    // ʹ�ú���strcpy
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], tmp);
            }
        }
    for (int i = 0; i < n; i++)
        puts(str[i]);
    return 0;
}
