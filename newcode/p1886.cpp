#include <bits/stdc++.h>
using namespace std;
int nj[1000010];
int qmax[1000010], qmin[1000010];
int hmax = 0, tmax = -1;
int hmin = 0, tmin = -1;
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> nj[i];
    }
    vector<int> ansmin, ansmax;
    for (int i = 0; i < n; i++)
    {
        while (hmin <= tmin && qmin[hmin] <= i - k)
            hmin++; // min单增返回hmin
        while (hmin <= tmin && nj[qmin[tmin]] >= nj[i])
            tmin--;
        qmin[++tmin] = i;
        while (hmax <= tmax && qmax[hmax] <= i - k)
            hmax++; // max单减返回hmax
        while (hmax <= tmax && nj[qmax[tmax]] <= nj[i])
            tmax--;
        qmax[++tmax] = i;
        if (i >= k-1)
        {
            ansmin.push_back(nj[qmin[hmin]]);
            ansmax.push_back(nj[qmax[hmax]]);
        }
    }
    for (int i = 0; i < ansmin.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << ansmin[i];
    }
    cout << '\n';
    for (int i = 0; i < ansmax.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << ansmax[i];
    }
    cout << '\n';

    return 0;
}//句式相同不要copy！！！！！！！！！！！！