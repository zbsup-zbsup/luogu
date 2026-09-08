#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int cnt[2005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = 0;
    int kind = 0;
    int minlen = n + 1, ansl = 0, ansr = 0;
    while (r < n)
    {
        cnt[a[r]]++;
        if (cnt[a[r]] == 1)
            kind++;
        r++;
        while (kind == m && l < r)
        {
            if (r - l < minlen)
            {
                minlen = r - l;
                ansl = l;
                ansr = r - 1;
            }
            cnt[a[l]]--;
            if (cnt[a[l]] == 0)
                kind--;
            l++;
        }
    }
    cout << ansl + 1 << " " << ansr + 1 << endl;
    return 0;
}