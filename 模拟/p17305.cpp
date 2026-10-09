#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<(10*n)-2<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"RDLD";
    }
    for(int i=0;i<n-1;i++)
    {
        cout<<"URRD";
    }
    for(int i=0;i<n;i++)
    {
        cout<<"L";
    }
    cout<<"DL";
    for(int i=0;i<n;i++)
    {
        cout<<"D";
    }
    return 0;
}