#include <bits/stdc++.h>
using namespace std;
void work()
{
    int n,m;
    cin>>n>>m;
    bool mapp[100010]={false};
    int x,y;
    int ans = n-1;
    mapp[1] = true;
    
    set<pair<int,int>> E;

    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        if(x>y) swap(x,y);
        E.insert({x,y});
        if(x==1)
        {
            mapp[y] = true;
            ans--;
        }
    }


    long long full = 1LL*n*(n-1)/2;
    if(full - m <= n-1)
    {
        vector<pair<int,int>> add;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(!E.count({i,j})) add.push_back({i,j});
        cout<<add.size()<<"\n";
        for(auto &e : add) cout<<e.first<<" "<<e.second<<"\n";
        return;
    }


    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(!mapp[i])
        {
            cout<<1<<" "<<i<<"\n";
        }
    }
    return;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        work();
    }
    return 0;
}