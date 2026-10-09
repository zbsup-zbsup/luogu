#include<bits/stdc++.h>
using namespace std;
long long ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(long long i=1;i<=901234;i++)
        for(long long j=1;j<=500001;j++)
            if((i-1)*567890+789456<(j-1)*876543+654321) ans++;
    cout<<ans;
    return 0;
}
