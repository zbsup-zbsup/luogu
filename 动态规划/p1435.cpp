#include <bits/stdc++.h>
using namespace std;
char b[1010];
int main()
{
    string a;
    cin>>a;
    int ans[1010];
    ans[0]=a.length();
    char c;
    int ixy=1;
    int al = a.length();
    for(int i=al;i>=al/2;i--)
    {
        int pl = i-1;
        c = a[pl];
        a.pop_back();
        int all = a.length();
        for(int j=0;j<all;j++)
        {
            if(c == a[j])
            {
                ans[ixy] = ans[ixy-1]-2;
                break;
            }
        }
        ixy++;
    }
    cout<<ans[ixy-1];
    return 0;
}