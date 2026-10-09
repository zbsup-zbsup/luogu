#include <bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    int n;
    int alice,bob,maxn=-1,flag;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)
        {
            bob=a[i];
        }
        if(i==n-1)
        {
            alice=a[i];
        }
        if(a[i]>maxn)
        {
            maxn = a[i];
            flag = i;
        }
    }
    if(alice < bob)
    {
        swap(a[0],a[n-1]);
    }
    else
    {
        swap(a[flag],a[n-1]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}