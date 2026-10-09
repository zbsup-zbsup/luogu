#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    string s;
    int ten;
    string ans;
    cin>>n>>s>>m;
    ten = stoi(s, nullptr, n);
    while(ten>0)
    {
        int flag;
        flag = ten%m;
        ten = (ten-flag)/m;
        if (flag>=10)
        {
            if(flag==10) ans.push_back('A');
            if(flag==11) ans.push_back('B');
            if(flag==12) ans.push_back('C');
            if(flag==13) ans.push_back('D');
            if(flag==14) ans.push_back('E');
            if(flag==15) ans.push_back('F');
        }
        else
        {
            ans.push_back(flag+'0');
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i];
    }
    return 0;
}//ac