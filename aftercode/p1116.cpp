#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[1010];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[j]>a[i])
                ans++;
    cout<<ans;
    return 0;
}