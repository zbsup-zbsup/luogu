#include <bits/stdc++.h>
using namespace std;
void work()
{
    int n;
    cin>>n;
    long long ans=100;
    int hits,pcnt;
    for(int i=0;i<n;i++)
    {
        cin>>hits>>pcnt;
        if(hits>50)
        {
            hits = 50;
        }
        ans = ans - hits;
        if(ans < 100)
        {
            ans = 100;
        }
        if(ans > 400)
        {
            ans = 400;
        }
        ans = ans + pcnt;
        if(ans < 100)
        {
            ans = 100;
        }
        if(ans > 400)
        {
            ans = 400;
        }
    }
    cout<<ans<<endl;
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