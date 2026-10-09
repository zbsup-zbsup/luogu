#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,m,c,d,k;
    int day1=0,flag=1,day=0;
    cin>>a>>b>>m>>c>>d>>k;
    if(c<a||(a==c&&d<b))
    {
        day = 1;
    }
    for(;m>=k;m=m-k)
    {
        b = b+k;
        while(b>=60)
        {
            b=b-60;
            a=a+1;
        }
        if(a>=24)
        {
            a=a-24;
            day1=1;
        }
        if(day==day1&&a>=c&&b>d&&flag)
        {
            if(flag == 1)
            {
                a=a-1;
                flag = 0;
            }
        }
        if(a<0)
        {
            a=23;
        }
        cout<<a<<" "<<b<<endl;
    }

    return 0;
}