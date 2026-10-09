#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d;
        if (d>=b)
        {
            e=c-a;
            f=d-b;
        }
        if (d<b)
        {
            e=c-a-1;
            f=d-b+60;
        }
    cout<<e<<" "<<f<<endl;
    return 0;
}