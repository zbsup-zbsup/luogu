#include <bits/stdc++.h>
using namespace std;
int xpy[1000010];
int main()
{
    int n, l, m;
    cin >> n >> l >> m;
    int x, maxn = -1, flag;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (maxn < x)
        {
            maxn = x;
            flag = i;
        }
        xpy[i] = x;
    }
    long long ans = 0, look = 1;
    if (flag != 0)
    {
        ans = xpy[flag] - xpy[flag - 1] + 1;
        xpy[flag - 1] = xpy[flag];
        if (xpy[flag - 1] == m) // 证明俩小朋友已经一样高了，且都是需要的最高值
            look = 0;
        else
        {
            xpy[flag - 1] = xpy[flag - 1] + 1;
            ans++;
        }
        if (look)
        {
            if (m - xpy[flag] != 0 && (m - xpy[flag]) % 2 == 0)
            {
                ans = ans + (m - xpy[flag]) / 2 * 3;
                xpy[flag] = m;
            }
            else if ((m - xpy[flag]) % 2 != 0)
            {
                ans = ans + (m - xpy[flag]+1) / 2 * 3 - 2;
                xpy[flag] = m;
            }
            if (m - xpy[flag - 1] != 0 && (m - xpy[flag - 1]) % 2 == 0)
            {
                ans = ans + (m - xpy[flag - 1]) / 2 * 3;
                xpy[flag - 1] = m;
            }
            else if ((m - xpy[flag - 1]) % 2 != 0)
            {
                ans = ans + (m - xpy[flag - 1]+1) / 2 * 3 - 2;
                xpy[flag - 1] = m;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(xpy[i]==m)
            continue;
        ans = ans + (m-xpy[i])+1;
    }
    cout<<ans<<endl;
    return 0;
}