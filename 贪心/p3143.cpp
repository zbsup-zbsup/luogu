#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int> len(n);
    int l=0;
    for(int r=0;r<n;r++)
    {
        while (a[r]-a[l]>k)
        {
            l++;
        }
        len[r]=r-l+1;
    }

    vector<int> pre(n);
    pre[0] = len [0];
    for(int i=1;i<n;i++)
    {
        pre[i]= max(pre[i-1],len[i]);
    }


    vector<int> suf(n);
    suf[n-1] = len[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suf[i]= max(suf[i+1],len[i]);
    }

    int ans = 0;
    for(int i=0;i<n-1;i++)
    {
        ans = max(ans,pre[i]+suf[i+1]);
    }
    cout<<ans<<endl;
    return 0;

}//并非ac代码，留了小bug，后续修改吧awa