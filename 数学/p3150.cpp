#include <bits/stdc++.h>
using namespace std;
void work(int x)
{
    if(x%2==0)
    {
        cout<<"zs wins"<<endl;
    }
    else 
    {
        cout<<"pb wins"<<endl;
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        work(x);
    }
}//ac，博弈论好(傻逼)题