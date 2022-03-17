#define _CRT_SECURE_NO_WARNINGS
/*
题目描述
给出一些由英文字符组成的大小写敏感的字符串的集合 s，请找到一个最长的字符串 x，使得对于 s 中任意字符串 y，x 或者是 y 的子串，或者 x 中的字符反序之后得到的新字符串是 y 的子串。

输入描述
输入的第一行是一个整数 t (1<=t<=10)，t 表示测试数据的数目。对于每一组测试数据，第一行是一个整数 n (1<=n<=100)，表示已经给出 n 个字符串。接下来 n 行，每行给出一个长度在 1 和 100 之间的字符串。

输出描述
对于每一组测试数据，输出一行，给出题目中要求的字符串 x 的长度。

样例输入
2
3
ABCD
BCDFF
BRCD

2
rose
orchid

样例输出
2
2

提示:
用于反转字符串的 strrev 函数属于非标准函数，OJ 编译器不予支持。
*/
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int t, n;
char str[100][101];

int searchMaxSubString(char*);
//Reinventing the wheel
char* my_strrev(char* str)
{
	char* right = str;
	char* left = str;
	char ch;
	while (*right)
		right++;
	right--;
	while (left < right)
	{
		ch = *left;
		*left++ = *right;
		*right-- = ch;
	}
	return(str);
}

int main()
{
	int minStrLen, subStrLen;
	char minStr[101];
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n;
			minStrLen = 100;
			for (int i = 0; i < n; i++)
			{
				cin >> str[i];
				if (strlen(str[i]) < minStrLen)
				{
					strcpy(minStr, str[i]);
					minStrLen = strlen(str[i]);
				}
			}
			subStrLen = searchMaxSubString(minStr);
			cout << subStrLen << endl;
		}
	}
	return 0;
}

int searchMaxSubString(char* source)
{
	int subStrLen, sourceStrLen;
	int i, j;
	bool foundMaxSubStr;
	char subStr[101], revSubStr[101];
	subStrLen = sourceStrLen = strlen(source);
	while (subStrLen > 0)
	{
		for (i = 0; i <= sourceStrLen - subStrLen; i++)
		{
			strncpy(subStr, source + i, subStrLen);
			strncpy(revSubStr, source + i, subStrLen);
			subStr[subStrLen] = revSubStr[subStrLen] = '\0';
			my_strrev(revSubStr);
			foundMaxSubStr = true;
			for (j = 0; j < n; j++) {
				if (strstr(str[j], subStr) == NULL && strstr(str[j], revSubStr) == NULL)
				{
					foundMaxSubStr = false;
					break;
				}
			}
			if (foundMaxSubStr)
				return subStrLen;
		}
		subStrLen--;
	}
	return 0;
}