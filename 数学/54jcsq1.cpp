#include <iostream>
using namespace std;

int main() {
    long long n, m, d;
    cin >> n >> m >> d;

    if (m < n * (d + 1)) {
        cout << -1 << endl;
        return 0;
    }

    long long S = m - n * (d + 1);
    long long c = min(n, S);
    long long ans = c + (S - c) / (d + 1);

    cout << ans << endl;
    return 0;
}