#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<4;i++)
    {
        if(i==2)
        {
            cout<<(60*1000)/n/2;
            continue;
        }
        cout<<(60*1000)/n;
    }
    return 0;
}