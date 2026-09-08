#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010],pos[100010];
long long ans;
int pos1=0,pos2=0,pos3=0;
void work()
{
    int n,mx=0;
    ans = 0,pos1 = 0;pos2 = 0;pos3 = 0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        mx = max(a[i],max(b[i],c[i]));
        if(mx == a[i])
        {
            pos[i]=1;
            pos1++;
        }
        else if(mx == b[i])
        {
            pos[i]=2;
            pos2++;
        }
        else
        {
            pos[i]=3;
            pos3++;
        }
        ans += mx;
    }
    if(pos1>n/2||pos2>n/2||pos3>n/2)
    {
        int need=0;
        int cost=0;
        vector<int> costv;
        if(pos1>n/2)
        {
            need = pos1 - n/2;
            for(int i=0;i<n;i++)
            {
                if(pos[i]==1)
                {
                    cost = a[i]-max(b[i],c[i]);
                    costv.push_back(cost);
                }
            }
        }
        else if(pos2>n/2)
        {
            need = pos2 - n/2;
            for(int i=0;i<n;i++)
            {
                if(pos[i]==2)
                {
                    cost = b[i]-max(a[i],c[i]);
                    costv.push_back(cost);
                }
            }
        }
        else if(pos3>n/2)
        {
            need = pos3 - n/2;
            for(int i=0;i<n;i++)
            {
                if(pos[i]==3)
                {
                    cost = c[i]-max(a[i],b[i]);
                    costv.push_back(cost);
                }
            }
        }
        sort(costv.begin(),costv.end());
        long long loss=0;
        for(int i=0;i<need;i++)
        {
            loss += costv[i]; 
        }
        cout<<ans - loss<<endl;
        return;
    }
    else
    {
        cout<<ans<<endl;
        return;
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        work();
    }
}//2025 csp-s -t1 ac，一道挺麻烦的贪心题