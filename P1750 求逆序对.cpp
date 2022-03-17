/*
题目描述

猫猫 TOM 和小老鼠 JERRY 最近又较量上了，但是毕竟都是成年人，他们已经不喜欢再玩那种你追我赶的游戏，现在他们喜欢玩统计。

最近，TOM 老猫查阅到一个人类称之为 “逆序对” 的东西，这东西是这样定义的：对于给定的一段正整数序列，逆序对就是序列中 ai>aj且 i<j 的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。注意序列中可能有重复数字。

输入格式
第一行，一个数 n，表示序列中有 n 个数。 第二行 n 个数，表示给定的序列。序列中每个数字不超过10^9。

输出格式
输出序列中逆序对的数目。

输入样例

6
5 4 2 6 3 1

输出样例

11

说明 / 提示

对于所有数据，n≤5×10^5
*/

#include <iostream>

long long ans;

using namespace std;

void merge(int *arr, int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0;
    int *temp = new int[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (int q = l; q <= r; ++q)
    {
        arr[q] = temp[q - l];
    }
    delete[] temp;
}

void mergeSort(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    unsigned int n;
    cin >> n;
    int *arr = new int[n];
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << ans << endl;
    delete[] arr;
    return 0;
}
