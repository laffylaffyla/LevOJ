#include <iostream>

using namespace std;

int main()
{
    int t;
    int arr[10] = {0};
    while (cin >> t)
    {
        while (t--)
        {
            string s;
            while (cin >> s)
            {
                int k = 0;
                for (int i = 0; i < 13; i++)
                {
                    if (s[i] == '-')
                    {
                        continue;
                    }
                    arr[k++] = s[i] - '0';
                }
                int sum = 0;
                for (int i = 0; i < 9; i++)
                {
                    sum += arr[i] * (i + 1);
                }
                sum %= 11;
                if (sum == arr[9])
                {
                    cout << "Right" << endl;
                }
                else
                {
                    cout << arr[0] << "-"
                         << arr[1] << arr[2] << arr[3] << "-"
                         << arr[4] << arr[5] << arr[6] << arr[7] << arr[8] << "-"
                         << sum << endl;
                }
            }
        }
    }
    return 0;
}
