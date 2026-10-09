#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int k;
    cin >> k;
    int flag = 0, minn = 10,zerolet=0;
    long long slimit = a.size()-k;
    while(k!=0)
    {
        for (int i = flag; i <= k+flag; i++)
        {
            if (int(a[i]) - 48 < minn)
            {
                minn = int(a[i]) - 48;
            }
        }
        for (int j = flag ;; j++)
        {
            if ((int(a[j]) - 48 == minn&&slimit!=0)||k<=0)
            {
                slimit--;
                flag = j+1;
                break;
            }
            else
            {
                k--;
                a[j]='0'-1;
            }
        }
        minn = 10;
    }
    int couttime=0;
    for(size_t i=0;i<a.size();i++)
    {
        if(int(a[i])!=47)
        {
            if(int(a[i])==48&&zerolet==0)
            {
                continue;
            }
            cout<<a[i];
            zerolet=1;
            couttime++;
        }
    }
    if(couttime==0)
    {
        cout<<0;
    }
    return 0;
}//这题超级有意思，ac
