#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long ans = 0,n,x;
    cin>>n;
    priority_queue<long long,vector<long long>,greater<long long>>pqmin;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        pqmin.push(x);
    }
    while (pqmin.size()>1)
    {
        long long a,b;
        a = pqmin.top();
        pqmin.pop();
        b = pqmin.top();
        pqmin.pop();
        pqmin.push(a+b);
        ans = ans + a + b;
    }
    
    cout<<ans;
    return 0;
}