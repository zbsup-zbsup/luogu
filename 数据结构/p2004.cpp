#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int s[1005][1005];
int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    s[1][1] = a[1][1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    int ans = -1e9, sum = 0,ansx=0,ansy=0;
    for (int i = 1; i+c-1 <= n; i++)
        for (int j = 1; j+c-1 <= m; j++)
        {
            sum = s[i + c - 1][j + c - 1] - s[i - 1][j + c - 1] - s[i + c - 1][j - 1] + s[i - 1][j - 1];
            if(ans<sum)
            {
                ansx = i;
                ansy = j;
                ans = sum;
            }
        }
    cout<<ansx<<" "<<ansy;
    return 0;
}