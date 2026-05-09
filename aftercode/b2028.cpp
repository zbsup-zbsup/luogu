#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c;
    cin>>n;
    a=n/100;
    b=(n-(a*100))/10;
    c=(n-a*100-b*10);
    cout<<c<<b<<a;
    return 0;
}