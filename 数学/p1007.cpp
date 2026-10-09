#include <bits/stdc++.h>
using namespace std;
int qiao[5010];
int main()
{
    int l,n,maxx=0,minn=0;
    cin>>l>>n;
    for(int i=0;i<n;i++)
    {
        cin>>qiao[i];
        maxx = max(maxx,max(qiao[i],l+1-qiao[i]));
        minn = max(minn,min(qiao[i],l+1-qiao[i]));
    }
    cout<<minn<<" "<<maxx<<endl;
    return 0;
}