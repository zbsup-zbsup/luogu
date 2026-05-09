#include <iostream>
using namespace std;

const int MOD = 998244353;

long long pow_mod(long long a, long long b, int mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        if (n == 1) {
            cout << "NO\n";
        } else {
            long long ans = (pow_mod(2, n, MOD) - 1 + MOD) % MOD;
            cout << ans << "\n";
        }
    }
    return 0;
}