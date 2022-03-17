/*
题目描述
有一个老板有一袋金块。每个月将有两名雇员会因其优异的表现分别被奖励一个金块。按规矩，排名第一的雇员将得到袋中最重的金块，排名第二的雇员将得到袋中最轻的金块。如果有新的金块周期性的加入袋中，则每个月都必须找出最轻和最重的金块。假设有一台比较重量的仪器，我们希望用最少的比较次数找出最轻和最重的金块。

输入描述
多组输入，每组两行数据： 第一行只有一个整数 n（2<=n<=100000） 第二行有 n 个正整数，表示每个金块的重量。

输出描述
对应每组输入，输出两个由空格分开的整数，表示最重和最轻的金块的重量

样例输入
7
8 7 5 6 9 4 5

样例输出
9 4
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* bullion = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> bullion[i];
	}
	sort(bullion, bullion + n);
	cout << bullion[n - 1] << " " << bullion[0] << endl;
	delete[] bullion;
	return 0;
}