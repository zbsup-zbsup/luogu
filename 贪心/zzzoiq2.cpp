#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<pair<long long, long long>> people(n); // p, w
    for (int i = 0; i < n; ++i) cin >> people[i].first;
    for (int i = 0; i < n; ++i) cin >> people[i].second;

    if (k == 1) 
    {
        cout << 0 << '\n';
        return 0;
    }

    sort(people.begin(), people.end(),
         [](auto &a, auto &b) { return a.first < b.first; });

    long long ans = LLONG_MAX;

    // 枚举作为最大值的那个人
    for (int i = k - 1; i < n; ++i) 
    {
        long long maxP = people[i].first;
        vector<long long> costs;
        costs.reserve(i);
        for (int j = 0; j < i; ++j) 
        {
            long long diff = maxP - people[j].first;
            costs.push_back(diff * people[j].second);
        }
        // 取最小的 k-1 个花费
        sort(costs.begin(), costs.end());
        long long sum = 0;
        for (int j = 0; j < k - 1; ++j) 
        {
            sum += costs[j];
        }
        if (sum < ans) ans = sum;
    }

    cout << ans << endl;
    return 0;
}