#include <bits/stdc++.h>
using namespace std;
int main()
{
    double s,v;
    cin>>s>>v;
    double time;
    time = s/v;
    time = ceil(time)+10;
    int timeint = time;
    int hours=0;
    while(timeint>=60)
    {
        hours++;
        timeint -= 60;
    }
    if(hours>8)
    {
        hours = 32-hours;
    }
    else
    {
        hours = 8-hours;
    }
    if(timeint==0)
    {
        if(hours<8)
            cout<<0<<hours<<":"<<00;
        else
            cout<<hours<<":"<<00;
    }
    else
    {
        if(timeint>=50)
            cout<<0<<hours-1<<":"<<0<<60-timeint;
        else
            cout<<0<<hours-1<<":"<<60-timeint;
    }
    return 0;
}