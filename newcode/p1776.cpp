#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int main()
{
    int n,W;
    cin>>n>>W;
    
    vector<pair<int,int>> items;//g,v

    
    for(int i=1;i<=n;i++)
    {
        int w,v,cnt;
        cin>>v>>w>>cnt;

        //拆分
        int k=1;
        while(cnt>0)
        {
            int take = min(k,cnt);
            items.push_back({w*take,v*take});
            cnt -= take;
            k *= 2;
        }
    }
    for(auto [ww,vv]:items)
    {
        for(int j=W;j>=ww;j--)
        {
            dp[j] = max(dp[j],dp[j-ww]+vv);
        }
    }
    cout<<dp[W];
    return 0;
}