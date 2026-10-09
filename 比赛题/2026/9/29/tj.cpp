#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin >> k;
    int hour, mine;
    int whour, wmine, cnt;
    for (int i = 0; i < k; i++)
    {
        cin >> hour >> mine;
        cnt = mine / 60;
        whour = hour % 24 + cnt;
        whour = whour %24;
        wmine = mine % 60;
        cout << whour << " " << wmine << endl;
    }
    return 0;
}