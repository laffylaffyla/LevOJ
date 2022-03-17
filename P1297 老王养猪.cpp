/*
题目描述
老王是一个老实巴交的农民，听说现在猪肉涨价很厉害，老王就修建了一个猪圈，养了 n 头猪（n<=1000），每天老王最多可以杀一头猪卖钱，获得的收益就是猪的体重。由于饲料价格上涨，每天给猪吃得越来越少，因此每过一天每头猪的体重都会下降 p [i]（当然，如果猪体重≤0 了，自然获利就是 0），问 k 天内老王的获得的最大收益是多少。

输入描述
第一行两个用一个空格分开的整数 n 和 k，分别表示猪的数目和天数

第二行 n 个用一个空格分开的整数，表示猪的初始重量 a [i](<=1000)；

第三行 n 个用一个空格分开的整数，表示每过一天每头猪的体重下降 p [i]。

输出描述
一行一个数，表示获得的最大收益。

样例输入
2 2
10 10
1 2

样例输出
19
*/

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1005;

struct pigData
{ 
    int initialWeight, decliningWeight;
}pig[N];

int f[N][N];

bool cmp(pigData x, pigData y)
{
    return x.decliningWeight > y.decliningWeight;
}

int main()
{
    int n, k, ans = 0;
    while (cin >> n >> k)
    {
        for (int i = 1; i <= n; i++)
            cin >> pig[i].initialWeight;
        for (int i = 1; i <= n; i++)
            cin >> pig[i].decliningWeight;
        sort(pig + 1, pig + n + 1, cmp);
        for (int i = 1; i <= n; i++)
            for (int j = k; j; j--)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + pig[i].initialWeight - pig[i].decliningWeight * (j - 1));
        for (int i = 1; i <= k; i++)
            ans = max(ans, f[n][i]);
        cout << ans << endl;
    }
    return 0;
}