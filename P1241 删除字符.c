#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>

int main()
{
	int i, j, c, k = 0;
	char a[100] = { 0 },  //��������ַ�������
		 b[100] = { 0 },  //���ǰ���*
		 d[100] = { 0 },  //��ź����*
		 e[100] = { 0 },  //����м�ɾ��*����ַ�
	     s[100] = { 0 };  //������
	while (gets(a) != NULL) //��������
	{
		c = strlen(a);//���㳤��
		for (i = 0; a[i] == '*'; i++)
		{
			b[i] = a[i];  //b���ǰ���*��i����ĸǰ*�ĸ���
		}
		for (j = c - 1; a[j] == '*'; j--)
		{
			d[k++] = a[j];   //d��ź����*����ʱ��j�Ǵӵ�һ����ĸ�����ĸ���
		}
		k = 0;//���ϴε�k��0
		for (j = 0; a[j] != '\0'; j++)
		{
			if (a[j] != '*')
				e[k++] = a[j];   //e[]����м�ȥ��*��Ľ����ȫ��a
		}
		/*���Ӳ����*/
		printf("%s", e);
		printf("%s\n", d);
		/*������������*/
		memset(a, '\0', sizeof(a));
		memset(b, '\0', sizeof(b));
		memset(d, '\0', sizeof(d));
		memset(e, '\0', sizeof(e));
		k = 0;
	}
	return 0;
}