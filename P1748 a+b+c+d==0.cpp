/*
求和问题可以被看做是以下的公式，给定 A，B，C，D 四个列表，计算有多少四元组满足 (a, b, c, d) ∈ A × B × C × D 且 a + b + c + d = 0。我们推测所有的列表都有 n 个数字。
注：不同的四元组是指元素位置不一样的四元组

数据范围
n<=2e3

样例输入
输入的第一个数字指明有 T 组。每一组这样描述，第一行是列表大小 n， 然后有 n 行。每一行都有四个整型数字，分别属于 A，B，C，D 四列。

样例输出
对于每一个测试用例，统计有多少个四元组满足他们的和是 0 。每一组数据一行。

Sample Input

1
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45

Sample Output

5
*/
/*
 * @Description: To iterate is human, to recurse divine.
 * @Autor: Recursion
 * @Date: 2022-03-23 09:44:28
 * @LastEditTime: 2022-03-23 12:03:40
 */
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[10000], b[10000], c[10000], d[10000];
int ab[200000001], cd[200000001];

void solve()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            ab[i * n + j] = a[i] + b[j];
            cd[i * n + j] = c[i] + d[j];
        }
    sort(ab, ab + n * n);
    sort(cd, cd + n * n);
    long long int ans = 0;
    for (int i = 0; i < n * n; i++)
    {
        int temp = -ab[i];
        ans += upper_bound(cd, cd + n * n, temp) - lower_bound(cd, cd + n * n, temp);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        solve();
    }
    return 0;
}
