#include <bits/stdc++.h>
using namespace std;
long long lxjh[100010],ic[100010],lf[100010],iclf[100010];
long long cnt[100010],d[100010];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>lxjh[i];
    }
    for(int i=1;i<n;i++)
    {
        cin>>lf[i]>>iclf[i]>>ic[i];
    }
    for(int i=1;i<m;i++)
    {
        int a = lxjh[i],b = lxjh[i+1];
        if(a>b)
        {
            swap(a,b);
        }
        d[a]+=1;
        d[b]-=1;
    }
    long long cost1,cost2,ans=0;
    for (int i = 1; i < n; i++)
    {
        cnt[i] = cnt[i-1] + d[i];
        cost1 = cnt[i]*lf[i];
        cost2 = cnt[i]*iclf[i]+ic[i];
        ans += min(cost1,cost2);
    }
    cout<<ans;
    return 0;
}