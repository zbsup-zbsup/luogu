#include <bits/stdc++.h>
using namespace std;
const int MAXN=1001;
int dp[MAXN][MAXN];
int w[MAXN],v[MAXN];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=w[i])
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}