#include <bits/stdc++.h>//byclrain
using namespace std;
void work(int n,int x,int y)
{
    if(x>0&&y<0&&n>=2)//这一步去解决不在同轴问题
    {
        cout<<"YES"<<endl;
        return;
    }
    else if(x>0&&y<0&&n<2)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(x<=0)//这一步保证同轴方向正确
    {
        x = -x;
        y = -y;
        swap(x,y);
    }
    if(x == y&&n==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    if(x == y&&x==0)
    {
        cout<<"YES"<<endl;
        return;
    }
    if((x-y)>=y&&n>=2)
    {
        long long x1=x,y1=y,n1=n;
        if(n1*y1<=x1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"NO"<<endl;
        return;
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,x,y;
        cin>>n>>x>>y;
        work(n,x,y);
    }
    return 0;
}//ac