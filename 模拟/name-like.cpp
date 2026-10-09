#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct note
{
    string name;
    int age;
}a[MAXN];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name>>a[i].age;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i].name<<" "<<a[i].age<<endl;
    }
    return 0;
} 