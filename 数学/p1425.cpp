#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int e=0,f=0;
    f = d-b;
    if(f<0)
    {
        e=e-1;
        f = 60+f;
    }
    else if(f>60)
    {
        e = e+1;
        f = f-60;
    }
    e = e+(c-a);
    cout<<e<<" "<<f;
    return 0;
}