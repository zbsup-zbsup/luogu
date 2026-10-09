#include <bits/stdc++.h>
using namespace std;
int a[5010];
int work()
{
    int n;
    long long nxd = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                nxd++;
            }
        }
    }
    int kill = n / 2;
    return kill + nxd;
}
int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        if (work() % 2 == 0)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Alice" << endl;
        }
    }
    return 0;
}