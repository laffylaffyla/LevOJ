/* 已知下面关键伪代码：

BUILD_MAX_HEAP(A)
for (int i = floor(A.length)/2; i >= 1; --i) {
    MAX_HEAPIFY(A, i)
}
--
MAX_HEAPIFY(A, i)
l = i * 2
r = i * 2 + 1

largest = i
if l <= A.length && A[l] > A[largest] {
    largest = l
}
if r <= A.length && A[r] > A[largest] {
    largest = r
}
if largest != i {
    swap(a[i], a[largest])
    MAX_HEAPIFY(A, largest)
}
--
HEAP-EXTRACT-MAX(A)
if A.length < 1 {
    error
}
max = A[1]
A[1] = A[A.length]
A.length = A.length - 1
MAX_HEAPIFY(A, 1)
return max
--
HEAP-INSERT(A, key)
A.length = A.length + 1
A[A.length] = key
i = A.length
while i > 1 && A[floor(i/2)] < A[i] {
    swap(A[i], A[floor(i/2)])
    i = floor(i/2)
}
本题要求使用大根堆维护一个优先队列，支持两种操作：

1 x 表示向优先队列插入一个值 x
2 表示弹出优先队列的最大值
输入描述

第一行一个整数 q，表示操作次数。

接下来 q 行，每行一个操作，格式为
-------
| 1 x |
| 2   |
-------
q≤100000，1≤x≤10000，保证不会对空队列执行操作 2。

输出描述

对于操作 1 ，输出伪代码中 swap 调用次数。

对于操作 2 ，输出一行隔开的两个值，分别是弹出的最大值，伪代码中 swap 调用次数。

样例输入

8
1 4
1 9
2
1 10
2
2
1 1
2

样例输出

0
1
9 1
1
10 1
4 1
0
1 1 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define N 100050
int n = 0;
int A[N];
int cnt;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cnt++;
}
void MAX_HEAPIFY(int A[], int i)
{
    int l = i * 2;
    int r = i * 2 + 1;
    int largest = i;
    if (l <= n && A[l] > A[largest])
    {
        largest = l;
    }
    if (r <= n && A[r] > A[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(A[i], A[largest]);
        MAX_HEAPIFY(A, largest);
    }
}
void BUILD_MAX_HEAP(int A[])
{
    for (int i = floor(n / 2); i >= 1; --i)
    {
        MAX_HEAPIFY(A, i);
    }
}

int HEAP_EXTRACT_MAX(int A[])
{
    if (n < 1)
    {
        return -1;
    }
    int max = A[1];
    swap(A[1], A[n]);
    n = n - 1;
    MAX_HEAPIFY(A, 1);
    return max;
}
void HEAP_INSERT(int A[], int key)
{
    n = n + 1;
    A[n] = key;
    int i = n;
    while (i > 1 && A[i / 2] < A[i])
    {
        swap(A[i], A[i / 2]);
        i = floor(i / 2);
    }
}

int main()
{
    int q, opt, x;
    cin >> q;
    while (q--)
    {
        cin >> opt;
        cnt = 0;
        if (opt == 1)
        {
            cin >> x;
            HEAP_INSERT(A, x);
            cout << cnt << endl;
        }
        if (opt == 2)
        {
            // BUILD_MAX_HEAP(A);
            cout << HEAP_EXTRACT_MAX(A) << " " << cnt << endl;
        }
    }
    return 0;
}