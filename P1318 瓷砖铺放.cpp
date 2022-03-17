/*
题目描述
有一长度为 N (1<=Ｎ<=10) 的地板，给定两种不同瓷砖：一种长度为 1，另一种长度为 2，数目不限。要将这个长度为 N 的地板铺满，一共有多少种不同的铺法？

例如，长度为 4 的地面一共有如下 5 种铺法：

4=1+1+1+1

4=2+1+1

4=1+2+1

4=1+1+2

4=2+2

请你编程用递归的方法求解上述问题。

输入描述
每行一个数 N，代表地板的长度

输出描述
每行一个数，代表所有不同的瓷砖铺放方法的总数

样例输入
3
4

样例输出
3
5
*/

#include <iostream>

using namespace std;

int count(int);

int main()
{
    int n;
    while (cin >> n)
    {
        cout << count(n) << endl;
    }
    return 0;
}

int count(int n)
{
    unsigned long f;
    if (n == 1)
        f = 1;
    else if (n == 2)
        f = 2;
    else
        f = count(n - 1) + count(n - 2);
    return f;
}