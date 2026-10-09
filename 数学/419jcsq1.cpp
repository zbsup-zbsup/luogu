#include <bits/stdc++.h>
using namespace std;
long long work(long long n, long long m, long long k)
{
    if(m==0)
    {
        return n;
    }
    long long mo;
    mo = n%k;
    if(mo+m<=k)
    {
        return mo;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int sl;
    long long n,m,k;
    cin>>sl;
    for(int i=0;i<sl;i++)
    {
        cin>>n>>m>>k;
        cout<<work(n,m,k)<<endl;
    }
    return 0;
}