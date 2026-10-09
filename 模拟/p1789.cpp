#include <bits/stdc++.h>
using namespace std;
bool n[115][115];
int m,k;
int main()
{
    int bc;
    cin>>bc;
    cin>>m>>k;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x += 1;
        y += 1;
        n[x][y] = 1;
        n[x-1][y] = 1; n[x-2][y] = 1; n[x+1][y] = 1; n[x+2][y] = 1;
        n[x][y+1]=1; n[x][y+2]=1; n[x][y-1]=1; n[x][y-2]=1;
        n[x+1][y+1]=1; n[x-1][y+1]=1; n[x+1][y-1]=1; n[x-1][y-1]=1;
    }
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        x += 1;
        y += 1;
        n[x][y] = 1;
        n[x+1][y]=1;n[x+2][y]=1;n[x-1][y]=1;n[x-2][y]=1;
        n[x][y+1]=1;n[x][y+2]=1;n[x][y-1]=1;n[x][y-2]=1;
        n[x+1][y+1]=1;n[x+1][y+2]=1;n[x+2][y+1]=1;n[x+2][y+2]=1;//1象限
        n[x+1][y-1]=1;n[x+1][y-2]=1;n[x+2][y-1]=1;n[x+2][y-2]=1;//4象限
        n[x-1][y+1]=1;n[x-1][y+2]=1;n[x-2][y+1]=1;n[x-2][y+2]=1;//2
        n[x-1][y-1]=1;n[x-1][y-2]=1;n[x-2][y-2]=1;n[x-2][y-1]=1;//3
    }
    long long ans=0;
    for(int i=2;i<bc+2;i++)
        for(int j=2;j<bc+2;j++)
        {
            if(!n[i][j])
                ans++;
        }
    cout<<ans;
    return 0;
}