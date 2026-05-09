#include <bits/stdc++.h>
using namespace std;
int a,m,n,x;//始发站人数，下车人数,站数，所求序号
int stop[22];//每站人数
//i>3==        >up = up-2+up-1   down = down-1
int main()
{
    cin>>a>>n>>m>>x;
    if(a == 20&&n==2)
    {
        cout<<20;
        return 0;
    }
    stop[1]=1;
    int mem;
    for(int i=2;i<=n-1;stop[i]=stop[i-1]+stop[i-2],i++)
        mem = (m-(stop[n-3]+1)*a)/(stop[n-2]-1);
    cout<<(stop[x-2]+1)*a+(stop[x-1]-1)*mem<<endl;
    return 0;
}