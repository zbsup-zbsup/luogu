#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
bool vis[100005];
void dfs(int u) 
{
    if(vis[u]) return;
    vis[u] = true;
    cout<<u<<" ";
    for(int v:g[u])dfs(v);
}
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:g[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                q.push(v);
            }
        }
    }
}
int main()
{   
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        sort(g[i].begin(),g[i].end());
    }
    dfs(1);
    cout<<endl;
    memset(vis,0,sizeof(vis));
    bfs(1);
    return 0;
}