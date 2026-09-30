#include <bits/stdc++.h>
using namespace std;
long long dp[10010000];
int tcost[100100],v[100010];
int main()
{
    int time,m;
    cin >> time >> m;
    for(int i=1;i<=m;i++)
    {
        cin>>tcost[i]>>v[i];
    }//输入

    for(int i=1;i<=m;i++)
    {
        for(int j=tcost[i];j<=time;j++)
        {
            dp[j] = max(dp[j],dp[j-tcost[i]]+v[i]);
        }
    }
    cout<<dp[time]<<endl;
    return 0;
}