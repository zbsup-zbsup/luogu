#include <bits/stdc++.h>
using namespace std;
const int MAXN=105;
int w[MAXN],v[MAXN],s[MAXN];
int dp[MAXN];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i]>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=v[i];j--)
        {
            for(int k=1;k<=s[i]&&j>=k*v[i];k++)
            {
                dp[j]=max(dp[j],dp[j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}