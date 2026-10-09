#include <bits/stdc++.h>
using namespace std;
void work()
{
    int n;
    int minn = 1e9;
    long long sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        minn = min(minn, a[i]);
        sum += a[i];
    }
    int anszt = 0;
    if (n == 1)
    {
        cout << "0" << endl;
        return;
    }
    if (n == 2)
    {
        for (int i = 0; i < n; i++)
        {
            if ((a[i] - minn) % 4 == 2)
            {
                cout << "2" << endl;
                return;
            }
            else if ((a[i] - minn) % 4 == 3 || (a[i] - minn) % 4 == 1)
            {
                anszt = 1;
            }
        }
        cout<<anszt<<endl;
        return;
    }
    if (n % 2 == 1)
    {
        cout << "0" << endl;
    }
    else
    {
        if (sum % 2 == 0)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }   
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        work();
    }
    return 0;
}