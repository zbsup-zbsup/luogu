#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,c;
    cin>>n>>c;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    long long ans =0;
    int l=0,r=0;
    for(int i=0;i<n;i++)
    {
        int b=a[i]-c;
        while(l<n&&a[l]<b)l++;
        while(r<n&&a[r]<=b)r++;
        ans+=(r-l);
    }
    cout<<ans;
}//双指针做法，不是很懂