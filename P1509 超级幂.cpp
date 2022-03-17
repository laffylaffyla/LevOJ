/*
题目描述
输入两个数 a, b，其中 b 极大。计算 a 的 b 次方对 1337 取模的结果。数据保证 a 在 int 范围内，b 小于 100 位。

输入描述
每个样例输入两行分别表示 a 和 b。

输出描述
每个样例输出一行表示：a 的 b 次方对 1337 取模的结果。

样例输入
2
3

样例输出
8
*/

#include<iostream>
#include<string>
#include<cstring>
#define BASE 1337

using namespace std;

int mypow(int, int);
int superPow(int, string);

//原型:Diffie-Hellman Key Exchange

int main()
{
	int a;
	string b;
	while (cin >> a >> b)
	{
        cout << superPow(a, b) << endl;
	}
    return 0;
}

// 计算 a 的 k 次方然后与 base 求模的结果
int mypow(int a, int k)
{
    // 对因子求模
    a %= BASE;
    int res = 1;
    for (int i = 0; i < k; i++)
    {
        // 这里有乘法，是潜在的溢出点
        res *= a;

        // 对乘法结果求模
        res %= BASE;
    }
    return res;
}

int superPow(int a, string b)
{
    if (b.empty())
        return 1;
    //字符串中储存ASCII码
    int last = b.back() - 48;
    b.pop_back();

    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);

    // 每次乘法都要求模
    return (part1 * part2) % BASE;
}

/*
版权声明：本文为CSDN博主「wolf鬼刀」的原创文章，遵循CC 4.0 BY - SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/wolfGuiDao/article/details/105865221
*/