#include <bits/stdc++.h>
using namespace std;
struct road
{
    int u,v,t;
};
bool cmp(road x, road y)
{
    return x.t < y.t;   // 时间小的排前面
}


int fa[1000010];
void bcj(int n)
{
    for(int i=0;i<=n;i++)
    {
        fa[i] = i;
    }
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x] = find(fa[x]);
}
void hb(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) fa[fx] = fy;
}



int main()
{
    int n,m;
    cin>>n>>m;
    vector<road> a(m);
    for(int i=0;i<m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].t;
    }
    sort(a.begin(),a.end(),cmp);
    bcj(n);
    int cnt = n;
    int ans = -1;
    for(auto r : a)
    {
        if(find(r.u)!=find(r.v))
        {
            hb(r.u,r.v);
            cnt--;
            if(cnt == 1)
            {
                ans = r.t;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}