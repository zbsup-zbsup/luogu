#include <bits/stdc++.h>
using namespace std;
int a[100010];
int ans[100010];
stack<int> cpu;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>0;i--)
    {
        if(cpu.empty())
        {
            ans[i]=0;
            cpu.push(i);
            continue;
        }
        while(!cpu.empty()&&a[cpu.top()]<=a[i])//弹出操作
        {
            cpu.pop();
        }
        if(cpu.empty())
        {
            ans[i]=0;
            cpu.push(i);
            continue;
        }
        ans[i] = cpu.top();
        cpu.push(i);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}