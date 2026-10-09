#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int gold[N][N];
int cost[N];
int rp[N];
int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> gold[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    memset(rp, -0x3f, sizeof(rp));
    rp[0] = 0;
    for (int t = 1; t <= m; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            for (int k = 1; k <= p && k <= t; k++)
            {
                int st = (i - k) % n;
                if (st <= 0)
                {
                    st = st + n;
                }
                int time = t-k+1;
                if(time<=0) break;
                sum += gold[st][time];
                rp[t] = max(rp[t],rp[t-k]+sum-cost[st]);
            }
        }
    }
    cout<<rp[m];
    return 0;
}//待学习