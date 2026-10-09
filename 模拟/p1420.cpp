#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n[10010];
    int o;
    cin>>o;
    for(int i=0;i<o;i++)
    {
        cin>>n[i];
    }
    int ans=0,maxn=-1;
    for(int i=1;i<o;i++)
    {
        if(n[i-1]+1==n[i])
            ans++;
        else
        {
            maxn = max(maxn,ans);
            ans = 0;
        }
    }
    cout<<max(maxn+1,ans+1);
}