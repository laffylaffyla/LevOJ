/*
题目描述
某工厂收到了 n 个产品的订单，这 n 个产品分别 A,B 两个车间加工，并且必须先在 A 车间加工后才可以到 B 车间加工。某个产品 i 在 A,B 两车间加工的时间分别为Ai,Bi。怎样安排这 n 个产品的加工顺序，才能使总的加工时间最短。这里所说的加工时间是指：从开始加工第一个产品到最后所有的产品都已在A,B 两车间加工完毕的时间。

输入描述
多组输入，每组数据的第一行仅一个正整数 n(0<n<1000) ，表示产品的数量。接下来 n 个数据是表示这 n 个产品在 A 车间加工各自所要的时间 (都是整数)。最后的 n 个数据是表示这 n 个产品在 B 车间加工各自所要的时间 (都是整数)。

输出描述
对于每组输入一个数据，表示最少的加工时间

样例输入

5
3 5 8 7 10
6 2 1 4 9

样例输出

34
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct Data
{
    int min, id;
};

bool cmp(Data x, Data y)
{
    return x.min < y.min;
}

int main()
{
    int n;
    while (cin >> n)
    {
        int *a = new int[n];
        int *b = new int[n];
        int *queue = new int[n];
        Data *process = new Data[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            process[i].min = min(a[i], b[i]);
            process[i].id = i;
        }
        sort(process, process + n, cmp);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (process[i].min == a[process[i].id])
            {
                queue[l++] = process[i].id;
            }
            else
            {
                queue[r--] = process[i].id;
            }
        }
        int ans = a[queue[0]];
        for (int i = 1; i < n; i++)
        {
            if (a[queue[i]] < b[queue[i - 1]])
            {
                b[queue[i]] = b[queue[i]] + b[queue[i - 1]] - a[queue[i]];
            }
            ans += a[queue[i]];
        }
        ans += b[queue[n - 1]];
        cout << ans << endl;
        delete[] a;
        delete[] b;
        delete[] queue;
        delete[] process;
    }
    return 0;
}