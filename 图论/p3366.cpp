#include <bits/stdc++.h>
using namespace std;
int fa[5090];
struct edge
{
    int u,v,t;
};
bool cmp(edge a,edge b)
{
    return a.t<b.t;
}


//并查集类
void csh(int n)
{
    for(int i=0;i<=n;i++)
    {
        fa[i]=i;
    }
    return;
}

int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x] = find(fa[x]);
}

void hb(int x,int y)
{
    fa[find(x)]=find(y);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<edge> q(m);
    for(int i=0;i<m;i++)//输入
    {
        cin>>q[i].u>>q[i].v>>q[i].t;
    }

    sort(q.begin(),q.end(),cmp);

    csh(n);
    int cnt = 0;
    long long ans =0;
    for(auto e:q)
    {
        if(find(e.u)!=find(e.v))
        {
            hb(e.u,e.v);
            ans+=e.t;
            cnt++;
            if(cnt == n-1)break;
        }
    }
    if (cnt == n - 1) cout << ans << endl;
    else cout << "orz" << endl;

    return 0;
}