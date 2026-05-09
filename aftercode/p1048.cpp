#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
int dp[MAXN][MAXN];
int jz[MAXN];
int sj[MAXN];
int main()
{
    int t;
    int n;
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> sj[i] >> jz[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= sj[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - sj[i]] + jz[i]);
            }
        }
    }
    cout<<dp[n][t] << endl;
}