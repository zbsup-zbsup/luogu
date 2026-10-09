// code by [clrain]
#include <bits/stdc++.h>
using namespace std;
long long a[100010];
long long pigmax = -1;
long long ans = 0;
int main()
{
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> a[i];
        if (s == "pig")
        {
            pigmax = max(pigmax, a[i]);
            a[i] = 0;
        }
    }
    ans = pigmax;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < pigmax)
        {
            ans += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}//ac by clrain