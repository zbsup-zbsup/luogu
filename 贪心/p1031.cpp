#include <bits/stdc++.h>
using namespace std;
int a[100010], num;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        num += a[i];
    }
    num /= n;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > num)
        {
            a[i + 1] = a[i + 1] + a[i] - num;
            a[i] = num;
            ans++;
        }
        else if (a[i] < num)
        {
            a[i + 1] = a[i + 1] - a[i] + num;
            a[i] = num;
            ans++;
        }
        else if (a[i] == num)
        {
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}