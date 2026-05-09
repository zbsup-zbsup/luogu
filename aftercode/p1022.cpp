// code by clrain
#include <bits/stdc++.h>
using namespace std;
string yyyc;
string wzs = "0";
// string xix = "";
int cs = 0, xs = 0, flag1 = 0; // flag1 means the num behind =;
int flag2 = 0;                 // flag2 = 0时为正     =1时为负数
int flag3 = 0;                 // flag3 用于存储用于判断有没有获取到未知数
int main(){
    cin>>yyyc;
    for (size_t i = 0; i < yyyc.size(); i++)
    {
        if (yyyc[i] >= '0' && yyyc[i] <= '9')
        {
            wzs += yyyc[i];
            if (i == yyyc.size() - 1)
            {
                if (flag1)
                {
                    flag2 = !flag2;
                }
                if (flag2)
                {
                    cs += stoi(wzs);
                    wzs = "0";
                }
                else
                {
                    cs -= stoi(wzs);
                    wzs = "0";
                }
            }
        }
        else if (yyyc[i] == '+' || yyyc[i] == '-' || yyyc[i] == '=')
        {
            if (flag1)
            {
                flag2 = !flag2;
            }
            if (flag2)
            {
                cs += stoi(wzs);
                wzs = "0";
            }
            else
            {
                cs -= stoi(wzs);
                wzs = "0";
            }
            if (yyyc[i] == '-')
            {
                flag2 = 1;
            }
            if (yyyc[i] == '+')
            {
                flag2 = 0;
            }
        }
        else if (yyyc[i] >= 'a' && yyyc[i] <= 'z')
        {
            if (stoi(wzs) == 0)
            {
                wzs = "1";
            }
            if (!flag3)
            {
                cout<<yyyc[i];
                flag3 = 1;
            }
            if (flag1)
            {
                flag2 = !flag2;
            }
            if (flag2)
            {
                xs -= stoi(wzs);
                wzs = "0";
            }
            else
            {
                xs += stoi(wzs);
                wzs = "0";
            }
        }
        if (yyyc[i] == '=')
        {
            flag1 = 1;
            flag2 = 0;
        }
    }
    double a = cs, b = xs;
    double ans = a/b;
    // cout<<"x=-12.667";
    cout<<'=';
    if(ans==-0.00)ans=0;
    printf("%.3f",ans);
    return 0;
} // code by clrain 80%
//debug first by zbsup(because logical reasoning problem)10%
//debug by Ceres_(because put out problem)10%
//ac