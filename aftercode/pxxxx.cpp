#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int chew[MAXN];
int main()
{
    int n,l,q,weiz,fw;
    cin>>n>>l>>q;
    for(int i=0;i<l;i++)
    {
        cin>>weiz>>fw;
        weiz=weiz-fw;
        for(int j=fw*2+1;j>0;j--)
        {
            if(weiz<=0) continue;
            chew[weiz]=j;
            weiz++;
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>weiz;
        if(chew[weiz]>0)
        {
            cout<<"Y"<<endl;
        }
        else
        {
            cout<<"N"<<endl;
        }
    }
    return 0;
}