#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,array_size=1e7+8;
int n,p,a[maxn],ans;
int num[array_size];
int f(int x)
{
    return x%(array_size-1);
}
void get_hash(int x)
{
    int tmp=x;
    while(tmp%p==0)tmp/=p;
    tmp=f(tmp);
    while(true)
    {
        if(!num[tmp])
        {
            num[tmp]=x;
            ans++;
            return;
        }
        else
        {
            if(x%num[tmp]==0)
            {
                if(x/num[tmp]!=p)
                {
                    ans++;
                    num[tmp]=x;
                }
                return;
            }
            else 
            {
                tmp = tmp == array_size?0:tmp+1;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        get_hash(a[i]);
    }
    printf("%d",ans);
    return 0;    
}//这是一道例题
//但我真不知道哈希表能干吗qwq