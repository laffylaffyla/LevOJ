/* 题目描述
牛牛有一个鱼缸，鱼缸里面已经有 n 条鱼，每条鱼的大小为 fishSize[i](1<i<n,均为正整数)，牛牛现在想把新捕捉的鱼放人鱼缸。鱼缸里存在着大鱼吃小鱼的 定律。经过观察，牛牛发现一条鱼 A 的大小为另外一条鱼 B 的大小的 2～10 倍（包括 2 倍大小和 10 倍大小）时鱼 A 会吃掉鱼 B。考虑到这个情况，牛牛要放入的鱼需要保证以下几点: （1）放进去的鱼是安全的，不会被其他鱼吃掉。 （2）这条鱼放进去也不能吃掉其他鱼。 （3）鱼缸里面存在的鱼已经相处了很久，不考虑它们互相捕食。 现在知道新放入鱼的大小范围 [minSize，maxSize] (考虑鱼的大小都是用整数表示），牛牛想知道有多少种大小的鱼可以放入这个鱼缸。

输入描述
输入数据包括 3 行， 第 1 行为新放入鱼的尺寸范围 [minSize,maxSize](1≤minSize,maxSize)，以空格分隔； 第 2 行为鱼缸里面已经有鱼的数量 n(1≤n)； 第 3 行为已经有的鱼的大小 fishSize[i](1≤fishSize[i])，以空格分隔。

输出描述
输出有多少种大小的鱼可以放入这个鱼缸，考虑鱼的大小都是用整数表示。

样例输入

1 12
1
1

样例输出

3 */
#include <iostream>

using namespace std;

int main()
{
    int min, max, n, ans = 0;
    cin >> min >> max >> n;
    int *fishSize = new int[n];
    for (int i = 0; i < n; i++)
        cin >> fishSize[i];
    bool flag;
    for (int i = min; i <= max; i++)
    {
        flag = true;
        for (int j = 0; j < n; j++)
        {
            if ((fishSize[j] >= i * 2 && fishSize[j] <= i * 10) || (i >= fishSize[j] * 2 && i <= fishSize[j] * 10))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans++;
    }
    cout << ans << endl;
    delete[] fishSize;
    return 0;
}
