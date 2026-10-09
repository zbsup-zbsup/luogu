#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    int n,s,x,ans=0;
    cin>>n>>s>>x;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==-1)
        {
            ans++;
            continue;
        }
        else
        {
            s=s-x+a[i];
            ans++;
        }
        if(s<=0)
        {
            break;
        }
    }
    if(s>0)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}