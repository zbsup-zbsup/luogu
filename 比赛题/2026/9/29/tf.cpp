#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
void work()
{
    int n;
    bool ans = 1; // true有解，false 无解
    cin >> n;
    double left = -1e9, right = 1e9;
    double a, b, c, x1, x2;
    long long pb;
    for (int i = 0; i < n; i++) // 任意一个方程无解立刻返回，值为NO
    {
        cin >> a >> b >> c;


        if (!ans) continue;//减少运算


        pb = (b * b) - (4 * a * c);
        if (pb <= 0) // if -> 无解    else ->有解
        {
            ans = false;
        }
        else // 求根
        {
            x1 = (-b + sqrt(pb)) / (2 * a);
            x2 = (-b - sqrt(pb)) / (2 * a);
            if (x1 > x2)
                swap(x1, x2); // 让x1始终<=x2  x1->left
            left = max(left, x1);
            right = min(right, x2);
        }
    }
    if (!ans) // 无解
    {
        cout << "NO" << "\n";
        return;
    }
    else
    {
        long long x = (long long)floor(left + eps) + 1;
        if (x < right - eps)
        {
            cout << "YES"<<"\n";
        }
        else
        {
            cout << "NO"<<"\n";
        }
    }
}

int main() // 组测试 10 000 * 200 000 ∑n≤2×10e5
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        work();
    }
}