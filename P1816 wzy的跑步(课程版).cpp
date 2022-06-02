/* 题目描述

wzy 在跑步，由于昨天下雨了，所以跑道上某些位置堆积了雨水。wzy 并不希望自己踩到水坑，所以当他将要踩到水坑时候他会选择跳过去。 具体的，跑道可以抽象为长度为n 的序列，wzy 从位置1 出发，目的地是到达位置n。跑道上会有m 个位置存在积水，他每次可以跳1 到k 单位长度正整数的距离，问wzy 最少可以踩到几次水坑到达位置n。

注意

此题目用来说明期末考试的出题形式，期末考试题目将包含多组测试数据，其中的一部分测试数据规模较小，可以使用暴力做法求解，完成暴力求解并通过这部分测试点将获得一定的分数；另一部分测试数据规模较大，需要使用正确的算法和数据结构进行求解，否则将会超时或超空间。

以本题为例，

第一个测试点数据规模为n≤50，m≤n，k≤n，使用下面给出的暴力代码可以通过。

第二个测试点数据规模为n≤10000，m≤n，k≤50，使用下面给出的暴力代码将会超时，需要使用 dp 代码才可通过。

在考试中，当你通过这道题两个测试点中的一个后，你会看到 50% 的进度展示，但是这并不意味着你一定会获得本题 50% 的分数。

暴力写法：

#include <stdio.h>
int ans;
int n, m, k, i, j, t;
int a[10001];
void jump(int current_location, int bad_move_count, int n, int k, int a[])
{
	//跳出跑道直接终止
	if (current_location > n)
	{
		return;
	}
	//跳到终点更新踩水数
	if (current_location == n)
	{
		if (bad_move_count < ans)
		{
			ans = bad_move_count;
		}
		return;
	}
	//枚举从当前位置向前的全部跳跃距离，进行递归
	for (int next_move = 1; next_move <= k; next_move++)
	{
		jump(current_location + next_move, bad_move_count + a[current_location + next_move], n, k, a);
	}
}
void solve()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		a[i] = 0;
	}
	scanf("%d", &m);
	scanf("%d", &k);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &j);
		a[j] = 1;
	}
	//输入部分结束，数组a中第j位存1代表在跑道位置j上有积水
	ans = 99999;
	//递归枚举全部的合法跳跃序列，参数为（当前位置，当前踩水量，n，k，a）
	jump(1, a[1], n, k, a);
	printf("%d\n", ans);
}
int main()
{

	//输入部分
	scanf("%d", &t);

	while (t--)
	{
		solve();
	}

	return 0;
}

dp 写法 */

#include <stdio.h>
int n, m, k, i, j, t;
int a[10001], dp[10001];
void solve()
{
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			a[i] = 0;
			dp[i] = 99999;
		}
		scanf("%d", &m);
		scanf("%d", &k);
		for (i = 0; i < m; i++)
		{
			scanf("%d", &j);
			a[j] = 1;
		}
		dp[1] = a[1];
		//输入部分结束，数组a中第j位存1代表在跑道位置j上有积水

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= k; j++)
			{
				//跳出跑道时终止
				if (i + j > n)
				{
					break;
				}
				//利用前进到i位置的最少踩水数dp[i]和i+j位置的水情a[i+j]更新前进到i+j位置的最少踩水数dp[i+j]
				if (dp[i] + a[i + j] < dp[i + j])
				{
					dp[i + j] = dp[i] + a[i + j];
				}
			}
		}
		printf("%d\n", dp[n]);
	}
}
int main()
{
	
	//输入部分
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}

	return 0;
}
/* 输入描述

输入第一行一个正整数T，表示数据组数。 接下来每个数据第一行n，m，k，分别代表路径的长度，积水的个数以及wzy 一次最远可以跨多远。

第二行共 m 个正整数ai，分别代表第i 个水坑的位置。

输出描述

输出共T 行，每行一个正整数，表示wzy 至少踩到几次水坑才能到达位置n。

样例输入

1
6 3 2
2 3 5
样例输出

1
样例解释

位置2，3，5 存在水坑。wzy 最初在位置1，他只能到达位置2，3。一种可行的走法为1−2−4−6，共踩1 次水坑。显然这是踩最少次水坑的方式之一。

数据规模

第一个测试点数据规模为n≤50，m≤n，k≤n。

第二个测试点数据规模为
n≤10000，m≤n，k≤50。 */