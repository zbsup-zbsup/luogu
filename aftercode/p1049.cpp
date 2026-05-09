#include <bits/stdc++.h>
using namespace std;
const int MAXN=1001;
int dp[30][20020];
int vl[MAXN];
int main()
{
    int v;
    int n;
    cin>>v>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>vl[i];
    }
    for(int i=1;i<=n;i++)
    {
        
    }
    
}
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V, n;
    cin >> V >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<bool> dp(V + 1, false);
    dp[0] = true;  // 容量0总是可达

    for (int v : a) {                // 遍历每个物品
        for (int j = V; j >= v; --j) // 逆序更新，保证每个物品只用一次
            if (dp[j - v]) dp[j] = true;
    }

    int ans = V;
    for (int i = V; i >= 0; --i)     // 从大到小找第一个可达容量
        if (dp[i]) { ans = V - i; break; }

    cout << ans << endl;
    return 0;
}
    */