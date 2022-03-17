/*
题目描述
计算仅含有加法计算的表达式的值。改表达式的长度不超过 200，中间没有空格和括号，且计算结果在整数范围内。

输入描述
若干行，每行一个仅含有加法的表达式。

输出描述
若干行，每行一个表达式的计算结果。

样例输入
1+2+3
12+23+21

样例输出
6
56
*/

#include <iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
    int sum = 0;
    string f;
    stack<int> addend;
    while (cin >> f)
    {
        for (int i = 0; i < f.size(); i++)
        {
            if (f[i] != '+')
            {
                addend.push(f[i] - '0');
            }
            else
            {
                int add = 0, temp = 1, size = addend.size();
                for (int i = 0; i < size; i++)
                {
                    add += addend.top() * temp;
                    temp *= 10;
                    addend.pop();
                }
                sum += add;
                stack<int>().swap(addend);
            }
        }
        int add = 0, temp = 1, size = addend.size();
        for (int i = 0; i < size; i++)
        {
            add += addend.top() * temp;
            temp *= 10;
            addend.pop();
        }
        sum += add;
        stack<int>().swap(addend);
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}