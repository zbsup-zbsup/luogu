#include <bits/stdc++.h>
using namespace std;
int sj[200010];
unordered_map<int,int> cnt;
int main()
{
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        cin>>sj[i];
        cnt[sj[i]]++;
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        int b = sj[i]-c;
        if(cnt.count(b))
        {
            ans+=cnt[b];
        }
    }
    cout<<ans<<endl;
}//哈希表原来这么好用，之前用数组做出类似效果真是太蠢了，浪费无意义空间嘛...