#include <bits/stdc++.h>
using namespace std;
int xpy[1000010];
// int work(int xpy[],int l)
// {
//         int max=-1;
//         for(int i=0;i<l;i++)
//         {
//             if(xpy[i]>max)
//             {
//                 max=xpy[i];
//             }
//         }
//         for(int i=l;i>0;i--)
//         {
//             if(xpy[i]>max)
//             {
//                 max=xpy[i];
//             }
//         }
//         return max;
// }
int main()
{
    int n,l,m;
    int max1=-1,max2=-1;
    int max=-1,maxn=-1;
    cin >> n >> l >> m;
    for(int i=0;i<n;i++)
    {
        cin>>xpy[i];
    }
    for(int i=0;i<l;i++)
        {
            if(xpy[i]>max)
            {
                max=xpy[i];
                max1=i;
            }
        }
    for(int i=n-1;i>=n-l;i--)
    {
        if(xpy[i]>maxn)
        {
            maxn=xpy[i];
            max2=i;
        }
    }
    int ans=0;
    if(maxn>max)//let max be max
    {
        swap(max,maxn);
        swap(max1,max2);
    }
    for(;max < m||maxn < m;)
    {
        ans = ans+max-maxn+1+1;
        maxn = maxn+max-maxn+1;

        if(maxn == m)
        {
            break;
        }
         ans = ans+maxn-max+1+1;
         max = max+maxn-max+1;
         if(max == m)
        {
            break;
        }
    }
    if(maxn>max)//let max be max
    {
        swap(max,maxn);
        swap(max1,max2);
    }
    xpy[max1]=max;
    xpy[max2]=maxn;
    for (int i = 0; i < n; i++)
    {
        if(xpy[i]!=m)
        {
            ans=ans+m-xpy[i]+1;
        }
    }
    cout<<ans<<endl;
    return 0; 
}