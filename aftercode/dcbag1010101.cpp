#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 2005;
int dp[M], v[N * M], w[N * M];
int main()
{
    int n, m, k = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int vv, ww, s;
        cin >> vv >> ww >> s;
        for (int i = 1; i <= s; i *= 2) // 二进制优化
            v[k] = vv * i, w[k++] = ww * i, s -= i;
        if (s > 0)
            v[k] = vv * s, w[k++] = ww * s;
    }
    for (int i = 0; i < k; i++) // 01背包
        for (int j = m; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[m] << endl;
    return 0;
}