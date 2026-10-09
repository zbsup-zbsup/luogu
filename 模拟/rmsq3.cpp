#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int n;
    int alice,bob;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(alice<bob)
        {
            cout<<"A";
            alice = alice+a[i];
        }
        else if(alice>=bob)
        {
            cout<<"B";
            bob = bob+a[i];
        }
    }
    return 0;
}