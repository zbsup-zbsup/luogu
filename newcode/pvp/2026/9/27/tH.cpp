#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    int q;
    cin >> n >> m >> q;

    // 切割点集合（包含边界 0 和 n/m）
    set<ll> cut_x, cut_y;

    // 段长多重集，用于快速取最大值
    multiset<ll> seg_x, seg_y;

    //加入边界
    cut_x.insert(0);
    cut_x.insert(n);
    cut_y.insert(0);
    cut_y.insert(m);
    seg_x.insert(n);
    seg_y.insert(m);

    while (q--)
    {
        int op;
        ll k;
        cin >> op >> k;

        if (op == 1)
        {
            // 纵向切割，影响 x 方向
            auto it = cut_x.lower_bound(k); // 右边最近的切割点
            ll r = *it;
            --it;       //求上一个切割点
            ll l = *it; // 左边最近的切割点

            // 删除旧段，插入两段新段
            seg_x.erase(seg_x.find(r - l));
            seg_x.insert(k - l);
            seg_x.insert(r - k);
            cut_x.insert(k);
        }

        else//同理
        {
            auto it = cut_y.lower_bound(k);
            ll r = *it;
            --it;
            ll l = *it;

            seg_y.erase(seg_y.find(r - l));
            seg_y.insert(k - l);
            seg_y.insert(r - k);
            cut_y.insert(k);
        }

        ll max_x = *seg_x.rbegin();
        ll max_y = *seg_y.rbegin();
        cout << max_x * max_y << '\n';
    }

    return 0;
}