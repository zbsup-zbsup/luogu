//code by clrain
#include <bits/stdc++.h>
using namespace std;
int num[200010];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    sort (num,num+n);
    int x=num[0],ans=1;
    for(int i=0;i<n;i++)
    {
        if(x == num[i+1])
        {
            ans++;
            continue;
        }
        else if(x!=num[i+1]||i==n-1)
        {
            cout<<x<<" "<<ans<<endl;
            x = num[i+1];
            ans = 1;
        }
    }
    return 0;

}//ac by clrain;