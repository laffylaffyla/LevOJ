#include <iostream>
using namespace std;
/* #define N 102
#define M 100002
int v[N], w[N];
int dp[M] = {0};

int main()
{
    int c, n;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= c; i++)
        for (int j = 0; j < n; j++)
            if (i >= v[j])
                dp[i] = max(dp[i], dp[i - v[j]] + w[j]);
    cout << dp[c] << endl;
    return 0;
}
 */
const int MAXN = 100;
int n, c;
int v[MAXN], w[MAXN], f[MAXN];

int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= c; j++)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[c] << endl;
    return 0;
}