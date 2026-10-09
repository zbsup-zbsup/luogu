#include <bits/stdc++.h>
using namespace std;
int hang[1050],lie[1050];//行上相同左右桌，同列上下桌
int hangs[1050],lies[1050];//用于排序
bool jxpx(int a,int b)
{
    return a>b;
}
int main()
{
    int m,n,k,l,d;//符合题目参数
    cin>>m>>n>>k>>l>>d;
    for(int i=0;i<d;i++)
    {
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        if(a==x)
        {
            hang[min(b,y)]++;
            hangs[min(b,y)]++;
        }
        if(b==y)
        {
            lie[min(a,x)]++;
            lies[min(a,x)]++;
        }
    }
    sort(hangs,hangs+m+1,jxpx);
    sort(lies,lies+n+1,jxpx);
    int hm,lm;
    hm = hangs[l-1];
    lm = lies[k-1];
    // for(int i=0;i<1000;i++)
    // {
    //     cout<<hangs[i]<<" ";
    // }
    for(int i=0;i<m;i++)
    {
        if(lie[i]>=lm)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(hang[i]>=hm)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
//ac!