#include <bits/stdc++.h>
using namespace std;
int mu[100010];
int n;
long long check(int x)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans += mu[i]/x;
    }
    return ans;
}
int main()
{
    int k;
    int maxn = -1;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>mu[i];
        maxn = max(maxn,mu[i]);
    }
    int ma=maxn,mi=1,x,ans=0;
    if(maxn == 0)
    {
        cout<<0;
        return 0;
    }
    while(mi<=ma)
    {
        int len = (ma+mi)/2;
        x=check(len);
        if(x<k)
        {
            ma=len-1;
        }
        if(x>=k)
        {
            ans = len;
            mi = len+1;
        }
    }
    cout<<ans;
    return 0;
}