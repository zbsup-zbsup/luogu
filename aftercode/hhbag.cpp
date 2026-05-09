#include <bits/stdc++.h>
using namespace std;
const int N =1005;
int s[N],v[N],w[N],dp[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>v[i]>>w[i]>>s[i];
        if(s[i]==-1)s[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]==0)
        {
            for(int j=v[i];j<=m;j++)
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
        for(int k=1;k<=s[i];s[i]-=k,k*=2)
        {
            for(int j=m;j>=0;j--)
                if(j>=k*v[i])
                    dp[j]=max(dp[j],dp[j-v[i]*k]+k*w[i]);
        }
        for(int j=m;j>=0;j--)
            if(j>=s[i]*v[i])
                dp[j]=max(dp[j],dp[j-s[i]*v[i]]+w[i]*s[i]);
    }
    cout<<dp[m]<<endl;
    return 0;
}