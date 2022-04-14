/*
题目描述
设有n 个正整数，将它们连成一排，组成一个最大的多位数。例如：输入n=3以及三个正整数 13,
312,343，则连成的最大数为 34331213

输入描述
第1行输入正整数个数n，下面n行输入n个整数

输出描述
一行，组成的最大整数

样例羭入

4
7
13
4
246

样例愉出

7424613
*/

//PJJ亲测代码

#include<iostream>
#include<string>
using namespace std;
void Sort(string *s,int n)
{
	for(int i=0;i<n-1;i++)
	for(int j=0;j<n-i-1;j++)
	{
		if(s[j]<s[j+1])
		{
			string t;
			t=s[j];
			s[j]=s[j+1];
			s[j+1]=t;
		}
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		string *num=new string[n];
		for(int i=0;i<n;i++) cin>>num[i];
		Sort(num,n);
		for(int i=0;i<n;i++) cout<<num[i];
		cout<<endl;
	}
	return 0;
}