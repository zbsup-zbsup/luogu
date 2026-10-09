#include <bits/stdc++.h>
using namespace std;
long long jss[1000010];
long long d[1000010],s[1000010],t[1000010];
long long dlss[1000010];
bool check(int mid,int n)
{
    memset(dlss,0,sizeof(dlss));
    for(int i=1;i<=mid;i++)
    {
        dlss[s[i]]+=d[i];
        dlss[t[i]+1]-=d[i];//为什么要加一//天数不同而已
    }

    long long cur =0;
    for(int i=1;i<=n;i++)
    {
        cur+=dlss[i];
        if(cur>jss[i]) return false;
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>jss[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>d[i]>>s[i]>>t[i];
    }
    long long lt = 1,rt=m,ans = 0;
    while(lt<=rt)
    {
        int mid = (lt+rt)/2;
        if(check(mid,n))
        {
            ans = mid;
            lt = mid+1;
        }
        else
        {
            rt = mid-1;
        }
    }
    if(ans == m) cout<<0<<endl;
    else
    {
        cout<<-1<<endl<<ans+1<<endl;
    }
    return 0;
}