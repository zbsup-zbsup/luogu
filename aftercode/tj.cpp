#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    const int INF = 1e9; // 足够大的数，表示不可达
    vector<int> dp(w + 1, INF);
    dp[0] = 0; // 凑出0元需要0张纸币
    
    // 完全背包：每种纸币无限张，求最小张数
    for (int i = 0; i < n; ++i) {
        for (int j = a[i]; j <= w; ++j) {
            if (dp[j - a[i]] != INF) {
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }
    }
    
    // 题目保证可以凑出，因此dp[w]一定不是INF
    cout << dp[w] << endl;
    
    return 0;
}