#include <iostream>

using namespace std;

const int MAXN = 500502;
int tower[MAXN], dp[MAXN];

int trans(int i, int j)
{
    return i * (i + 1) / 2 + j;
}

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < (1 + n) * n / 2; i++)
            cin >> tower[i];
        for (int i = 0; i < n; i++)
            dp[trans(n - 1, i)] = tower[trans(n - 1, i)];
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < i + 1; j++)
                dp[trans(i, j)] = tower[trans(i, j)] + ((dp[trans(i + 1, j)] > dp[trans(i + 1, j + 1)]) ? dp[trans(i + 1, j + 1)] : dp[trans(i + 1, j)]);
        cout << dp[0] << endl;
    }
    return 0;
}
