#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int fx[]={0,-2,-1, 1, 2, 2, 1,-1,-2};
const int fy[]={0, 1, 2, 2, 1,-1,-2,-2,-1};


int bx,by,mx,my;
ll f[40][40];
bool st[40][40];


int main()
{
    cin>>bx>>by>>mx>>my;
    bx+=2; by+=2; mx+=2; my+=2;
    f[2][1] = 1;
    st[mx][my] = 1;
    for(int i=1;i<=8;i++)
    {
        st[mx+fx[i]][my+fy[i]]=1;
    }

    for(int i=2;i<=bx;i++)
    {
        for(int j=2;j<=by;j++)
        {
            if(st[i][j]) continue;
            f[i][j]=f[i-1][j]+f[i][j-1];
        }
    }
    printf("%lld\n",f[bx][by]);
    return 0;
}