#include<iostream>
using namespace std;

struct item
{
	int V,W;
}T[20001];

long long Max(long long a,long long b)
{
	return a>b?a:b;
}

int main()
{
	int n,c;
	while(scanf("%d",&c)!=EOF)
	{
		scanf("%d",&n);
		long long dp[10001][2]={{0}};
		for(int i=1;i<=n;i++) 
		{
			cin>>T[i].V>>T[i].W;
			for(int j=1;j<=c;j++)
			{
				if(j>=T[i].V)
				{
					dp[j][1]=Max(dp[j][0],dp[j-T[i].V][0]+T[i].W);
				}
				else dp[j][1]=dp[j][0];
			}
			for(int j=1;j<=c;j++) dp[j][0]=dp[j][1];
		}
		cout<<dp[c][1]<<endl;
	}
}
