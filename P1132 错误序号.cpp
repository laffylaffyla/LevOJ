/* #include <iostream>
#include <cmath>

using namespace std;

int n;
long long dp[1002] = {0};

int main()
{
    dp[1] = 1;
    while (cin >> n)
    {
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 9 * dp[i - 1] + pow(10, i - 1);
        }
        cout << dp[n] << endl;
    }
    return 0;
} */

#include <cstdio>
char a[1007][1100] = {};
int main()
{
    int i, j, n;
    a[1][0] = 1;
    for (i = 1; i < 1003; i++)
    {
        a[i + 1][i] = 1;
        for (j = 0; j < 1000; j++)
        {
            a[i + 1][j] += a[i][j] * 9;
            a[i + 1][j + 1] += a[i + 1][j] / 10;
            a[i + 1][j] %= 10;
        }
    }
    while (~scanf("%d", &n))
    {
        for (i = 1005; a[n][i] == 0; i--)
            ;
        for (; i + 1; i--)
            printf("%d", a[n][i]);
        putchar('\n');
    }
    return 0;
}
