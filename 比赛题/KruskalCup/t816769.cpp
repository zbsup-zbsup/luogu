#include <bits/stdc++.h>
using namespace std;
int a[100010];
int ans[100010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n/2;i++)//正序第一遍
    {
        // if(a[i]>ans[i-1])
        // {
        //     ans[i]=a[i];
        // }
        // else
        // {
        //     ans[i] = ans[i-1];
        // }
        ans[i]=max(ans[i-1],a[i]);
    }
    int cnt = 1;//用于计数
    for(int i=n;i>=n/2;i--)//尾序一遍
    {
        ans[cnt]=max(ans[cnt],max(ans[cnt-1],a[i]));
        cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==0)
        {
            ans[i] = ans[i-1];
        }
        cout<<ans[i]<<" ";
    }
    return 0;
}//ac