#include <iostream>

using namespace std;

int n;
int dp[10] = {0};

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    cin >> n;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] += dp[j];
        }
        dp[i] += 1;
    }
    cout << dp[n] << endl;
}