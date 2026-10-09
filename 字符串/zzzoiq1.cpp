#include <bits/stdc++.h>
using namespace std;
string username, pw;
void work()
{
    bool unf = 1, pwf = 0;
    bool pwf6 = 1, pwfA = 0, pwfnum = 0, pwfa = 0;
    if (username.size() != 7)
    {
        unf = false;
    }
    bool unf0 = 0;
    for (int i = 3; i < username.size(); i++)
    {
        if (username[i] != '0')
        {
            unf0 = 1;
        }
    }
    if (pw.size() < 6)
    {
        pwf6 = false;
    }
    for (int i = 0; i < pw.size(); i++)
    {
        if (pw[i] >= 65 && pw[i] <= 90)
            pwfA = true;
        if (pw[i] >= 97 && pw[i] <= 122)
            pwfa = true;
        if (pw[i] >= 48 && pw[i] <= 57)
            pwfnum = true;
    }
    if (pwfA && pwfa && pwf6 && pwfnum)
        pwf = true;
    if (pwf && unf && unf0)
    {
        cout << "Accept" << endl;
        return;
    }
    else if (!unf)
    {
        cout << "Wrong Name" << endl;
        return;
    }
    else if (!unf0)
    {
        cout << "Wrong Name" << endl;
        return;
    }
    else if (!pwf)
    {
        cout << "Wrong Password" << endl;
        return;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> username >> pw;
        work();
    }
}