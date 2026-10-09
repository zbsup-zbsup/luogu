#include <bits/stdc++.h>
using namespace std;

const int MAXN=100010;
int a[MAXN],b[MAXN];
vector<int> bxzl[MAXN];
int sz[MAXN];
vector<int> hx[MAXN];
int ans = 0;

void mergeSub(vector<int>& a,vector<int>& b)
{
    if(a.size()<b.size())
        swap(a,b);
    a.insert(a.end(),b.begin(),b.end());
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    vector<int>().swap(b);
}

int simulate(const vector<int>& arr,int target)
{
    int k = 0;
    int xix = 0;
    int n = arr.size();
    while(true)
    {
        auto it = upper_bound(arr.begin()+xix,arr.end(),k);
        if(it == arr.end())
            break;
        k = *it;
        if(k>=target) break;
        xix = it -arr.begin() + 1;
    }
    return k;
}

void dfs(int u,int gen)
{
    sz[u] = 1;
    hx[u].clear();
    hx[u].push_back(a[u]);
    for(int v:bxzl[u])
    {
        if(v == gen)
            continue;
        dfs(v,u);
        sz[u] += sz[v];
        mergeSub(hx[u],hx[v]);
    }
}
int work(int n,int d)
{
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin >> u >> v;
        bxzl[u].push_back(v);
        bxzl[v].push_back(u); 
    }
    if(b[d]>2)
    {
        return 0;
    }
    dfs(d,0);
    for(int v: bxzl[d])
    {
        int max_k = simulate(hx[v],a[d]);
        if(max_k >= a[d])
        {
            ans += sz[v];
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,d;
        cin>>n>>d;
        cout<<work(n,d)<<endl;
    }
    return 0;
}