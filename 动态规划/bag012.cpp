#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int main()
{
    int n,m,v,w;
       cin>>n>>m;
       for(int i=1;i<=n;i++)
       {
	cin>>v>>w;
	for(int j=m;j>=v;j--)
	{
	      dp[j]=max(dp[j],dp[j-v]+w);
	}
        }
        cout<<dp[m]<<endl;
        return 0;
}