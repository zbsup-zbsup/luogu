#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    vector<int> a;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a.push_back(s[i] - '0');
        }
    }
    sort(a.begin(), a.end());
    for(int i = (int)a.size() - 1; i >= 0; i--)  // 从 size-1 开始
    {
        cout << a[i];
    }
    return 0;
}