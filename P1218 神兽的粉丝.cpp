#include <iostream>

using namespace std;

int n, cnt = 0;
int arr[102][102];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (!arr[i][j] && arr[j][i])
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}