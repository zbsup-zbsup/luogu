#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010, MAXM = 2010;
int n, h, de; // n=树量   h=树高   de=跳跃损耗
int a[MAXN][MAXM], dp[MAXN][MAXM], hbest[MAXN];
int main() // a柿子位置，dp就是dp,hbest表示某高度最好选择
{
    cin >> n >> h >> de;
    for (int i = 1; i <= n; i++)
    {
        int ncin, sz;
        scanf("%d", &ncin);
        while (ncin--)
        {
            scanf("%d", &sz);
            a[i][sz]++;
        }
    }
    int maxn = 0;
    for (int j = h; j >= 0; j--)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][j] = a[i][j] + dp[i][j + 1];
            dp[i][j] = max(dp[i][j], hbest[j + de] + a[i][j]);
            hbest[j] = max(hbest[j], dp[i][j]);
            maxn = max(maxn, dp[i][j]);
        }
    }
    cout << maxn;
    return 0;
}