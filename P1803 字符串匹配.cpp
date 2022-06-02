/* 题目描述

给定一个字符串A 和一个字符串B，求B 在A 中的出现次数。A 和B 中的字符均为英语大写字母或小写字母。
A 中不同位置出现的B 可重叠。

输入描述

输入共两行，分别是字符串A 和字符串B。

输出描述

输出一个整数，表示B 在A 中的出现次数。

样例输入

zyzyzyz
zyz
样例输出

3
数据范围

保证所有字符串长度≤10^6
 */

#include <iostream>
#include <string>

using namespace std;
string a, b;
int cnt = 0, po = -1;
int main()
{
    cin >> a >> b;
    while (1)
    {
        po = a.find(b, po + 1);
        cnt++;
        if (po == -1)
            break;
    }
    cout << cnt - 1 << endl;
}