#include <bits/stdc++.h>
using namespace std;
int k[200010], b[200010];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i] >> b[i];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int xq,yq,ans = 0;
        cin>>xq>>yq;
        for(int i=0;i<n;i++)//丑陋的循环qwq
        {
            if(k[i]*xq+b[i]==yq) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
note
第一次提交方法没有问题，最后一个组全tle，做一个数据判断换算法试试
*/