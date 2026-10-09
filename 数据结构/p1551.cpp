#include <bits/stdc++.h>
using namespace std;
const int N=20000+5;
int n,m;
int f[N];
int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
int main()
{
    int a,b,x,y,Q;
    cin>>n>>m>>Q;
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        x=find(a);
        y=find(b);
        if(x!=y)f[x]=y;
    }
    for(int i=1;i<=Q;i++)
    {
        cin>>x>>y;
        if(find(x)!=find(y))cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}