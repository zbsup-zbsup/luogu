#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    int a[n+10];
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    nth_element(a,a+k,a+n);
    cout<<a[k];
    return 0;
}//ac这什么世纪水题（其实是水做法了）