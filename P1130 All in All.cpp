/*
题目描述
给定两个字符串 s 和 t，请判断 s 是否是 t 的子序列。即从 t 中删除一些字符，将剩余的字符连接起来，即可获得 s。

输入描述
包括若干组测试数据。每组测试数据由两个 ASCII 码的数字和字母串 s 和 t 组成， s 和 t 的长度不超过 100000。

输出描述
对每组测试数据，如果 s 是 t 的子序列则输出 Yes;，否则输出 No。

样例输入
sequence subsequence
person compression
caseDoesMatter CaseDoesMatter

样例输出
Yes
No
No
*/

#include<iostream>
#include<string>

using namespace std;

bool isSubsequence(string, string);

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
        if (isSubsequence(s, t))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
	}
    return 0;
}

bool isSubsequence(string s, string t)
{
    int n = s.length();
    int m = t.length();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
            i++;
        j++;
    }
    return i == n;
}