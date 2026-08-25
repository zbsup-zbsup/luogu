#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    
    // 最小公倍数必须是最大公约数的倍数，否则无解
    if (y % x != 0) {
        cout << 0;
        return 0;
    }
    
    long long prod = x * y;  // P * Q = x0 * y0
    int ans = 0;
    
    for (long long i = 1; i * i <= prod; i++) {
        if (prod % i == 0) {
            long long j = prod / i;
            if (__gcd(i, j) == x) {  // 检查最大公约数是否为 x0
                if (i == j)
                    ans++;      // P = Q 时只算一种顺序
                else
                    ans += 2;   // P, Q 和 Q, P 两种顺序
            }
        }
    }
    
    cout << ans;
    return 0;
}