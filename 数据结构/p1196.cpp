#include <bits/stdc++.h>
using namespace std;
const int N=30000+5;
int f[N],dis[N],sz[N];
int find(int x)
{
    if(f[x]==x)return x;
    int ff=find(f[x]);
    dis[x]+=dis[f[x]];
    return f[x]=ff;
}
void Union(int x,int y)
{
    int u=find(x),v=find(y);
    if(u==v)return;
    f[u]=v;
    dis[u]+=sz[v];
    sz[v]+=sz[u];
}
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=30000;++i)f[i]=i,sz[i]=1;
     while(T--)
     {     char ch[3];
           int x,y;
           scanf("%s",ch);
           scanf("%d%d",&x,&y);
           if(ch[0]=='M')Union(x,y);
           else
           {
	 int u=find(x),v=find(y);
	 if(u!=v)printf("-1\n");
	 else printf("%d\n",abs(dis[x]-dis[y])-1);
           }
      }
      return 0;
}