#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        a[i]=(i)*k+a[i];
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            for(int l=1;l<=j-i;l++)
            {
                for(int m=i;m<=j-l;m++)
                {
                    ans=ans+a[m+l]-a[m];
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}