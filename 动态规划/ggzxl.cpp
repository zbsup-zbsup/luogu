#include <bits/stdc++.h>
using namespace std;
const int MAXN=5000000;
int t[MAXN],s[MAXN];
int F[MAXN][MAXN];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            F[i][j]=max(F[i-1][j],F[i][j-1]);
            if(s[i-1]==t[j-1]) F[i][j]=max(F[i][j],F[i-1][j-1]+1);
        }
    }
    cout<<F[n][n]<<endl;
    return 0;
}