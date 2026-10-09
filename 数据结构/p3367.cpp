#include <bits/stdc++.h>
using namespace std;
int a[1000010];
void bcj(int n)
{
    for(int i=0;i<=n;i++)
    {
        a[i] = i;
    }
}
int find(int x)
{
    if(a[x]==x) return x;
    return a[x] = find(a[x]);
}
void hb(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) a[fx] = fy;
}
int main()
{
    int n;
    cin>>n;
    bcj(n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int x,y;
            cin>>x>>y;
            hb(x,y);
        }
        if(a==2)
        {
            int x,y;
            cin>>x>>y;
            if(find(x) == find(y))
            {
                cout<<"Y"<<endl;
            }
            else
            {
                cout<<"N"<<endl;
            }
        }
    }
    return 0;
}