#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y;
    long long ans=0;
    cin >> x >> y;
    /*
        xyyyyyyx
        xyyyyyyx
        xyyyyyyx
    */
   if(x>y)
   {
        swap(x,y);
   }
   while(x>0&&y>0)
   {
        if(x>y)swap(x,y);
        long long cic;
        cic = y/x;
        ans = ans+(x*4*cic);
        y = y-(cic*x);
   }
   cout<<ans;
   return 0;
}//ac by zbsup