#include <bits/stdc++.h>
using namespace std;
struct ioer
{
    string name;
    long age;
};
int y,m,d;
int  main()
{
    ioer ioers[110];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ioers[i].name>>y>>m>>d;
        ioers[i].age = y*10000+m*100+d;
    }
    sort (ioers, ioers + n, [](const ioer& a, const ioer& b) 
    {
       return a.age < b.age;
    });
    for(int i=0;i<n;i++)
    {
        cout<<ioers[i].name<<endl;
    }
    return 0;
}
//80分非ac代码