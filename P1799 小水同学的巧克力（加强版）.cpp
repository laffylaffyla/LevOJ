/* 题目描述
小水喜欢吃正方形的巧克力。但是小水现在手里只有 n 块长方形的巧克力，小水可以从这些巧克力上切下一些正方形的巧克力。为了控制饮食，小水最多只能吃 m 块正方形巧克力，小水想知道，他最多能吃到多少面积的正方形巧克力。

输入描述
第一行两个正整数 n,m(1≤n≤10^6,1≤m≤10^5), 意义如题面所示。 接下来 n 行， 每行两个正整数 a,b(1≤a,b≤100000) 表示长方形巧克力的边长。

输出描述
输出一个正整数，表示小水最多能吃多少面积的正方形巧克力。

样例输入

2 3
2 3
2 3
样例输出

9 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
long long ans = 0;
int sum = 0;
vector<long long> choco;

void breakChoco(long long a, long long b)
{
    long long t;
    if (a > 0 && b > 0)
    {
        if (a > b)
        {
            t = b * b;
            choco.push_back(t);
            breakChoco(a - b, b);
        }
        else
        {
            t = a * a;
            choco.push_back(t);
            breakChoco(b - a, a);
        }
    }
    sum++;
}

void eatChoco()
{
    m = m < choco.size() ? m : choco.size();
    for (int i = 0; i < m; i++)
    {
        ans += choco[i];
    }
}

int main()
{
    cin >> n >> m;
    long long a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        breakChoco(a, b);
        if (sum > m)
        {
            sort(choco.begin(), choco.end(), greater<long long>());
            choco.erase(choco.begin() + m, choco.end());
            sum = 0;
        }
    }
    sort(choco.begin(), choco.end(), greater<long long>());
    eatChoco();
    cout << ans << endl;
    return 0;
}