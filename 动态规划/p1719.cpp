#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int col[105][105]; // 前缀和
int maxs(int arr[], int m)
{
    int dp = arr[1];
    int ans = arr[1];
    for (int i = 2; i <= m; i++)
    {
        dp = max(arr[i], dp + arr[i]);
        ans = max(ans, dp);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            col[i][j] = col[i - 1][j] + a[i][j];
    int ans = -1e9;
    for (int top = 1; top <= n; top++)
    {
        for (int bottom = top; bottom <= n; bottom++)
        {
            int b[105];
            for (int j = 1; j <= n; j++)
            {
                b[j] = col[bottom][j] - col[top - 1][j];
            }
            int cur = maxs(b, n);
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}//很好玩的压行想法，值得复习！