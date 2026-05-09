#include <bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int kj[MAXN][MAXN];
int n;
int a,b,ch,hi;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>ch>>hi;
        for(int gfx=b;gfx<hi+b;gfx++)
        {
            for(int xfx=a;xfx<ch+a;xfx++)
            {
                kj[gfx][xfx]=i;
            }
        }
    }
    int x,y;
    cin>>x>>y;
    if(kj[y][x]) cout<<kj[y][x]<<endl;
    else cout<<"-1"<<endl;
    return 0;
}