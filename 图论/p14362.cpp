// #include <bits/stdc++.h>
// using namespace std;

// struct edge
// {
//     int u, v, w;
// };
// bool cmp(edge a, edge b)
// {
//     return a.w < b.w; // 边权升序
// }

// int fa[10050];
// void init(int n)
// {
//     for (int i = 1; i <= n; i++)
//         fa[i] = i;
// }

// int find(int x)
// {
//     if (fa[x] == x)
//         return x;
//     return fa[x] = find(fa[x]);
// }

// void merge(int x, int y)
// {
//     fa[find(x)] = find(y);
// }

// int main()
// {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<edge> edges(m);
//     for (int i = 0; i < m; i++)
//     {
//         cin >> edges[i].u >> edges[i].v >> edges[i].w;
//     }

//     sort(edges.begin(), edges.end(), cmp);

//     init(n);
//     int cnt = 0;       // 已合并的边数
//     long long ans = 0; // 总权值
//     vector<edge> base;


//     for (auto e : edges)
//     {
//         if (find(e.u) != find(e.v))
//         {
//             merge(e.u, e.v);
//             base.push_back(e);
//             ans += e.w;
//             cnt++;
//             if (cnt == n - 1)
//                 break; // 已经连通
//         }
//     }

//     cout << ans;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int u, v;
    ll w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int n, m, k;
vector<Edge> base;          // 原图 MST 的边
vector<Edge> town[15];      // 每个乡镇的边，已按 w 升序
ll c[15];                   // 乡镇改造费用

int fa[10015];
int city_cnt[10015];        // 每个集合包含的城市数量

void init_dsu(int total) {
    for (int i = 1; i <= total; i++) {
        fa[i] = i;
        city_cnt[i] = (i <= n ? 1 : 0);
    }
}

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        fa[fx] = fy;
        city_cnt[fy] += city_cnt[fx];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    // ---------- 第一步：原图 MST ----------
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end(), cmp);

    init_dsu(n);  // 只用城市节点
    int cnt = 0;
    for (auto& e : edges) {
        if (find(e.u) != find(e.v)) {
            merge(e.u, e.v);
            base.push_back(e);
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    // base 已按 w 升序

    // ---------- 第二步：读入乡镇信息 ----------
    for (int j = 1; j <= k; j++) {
        cin >> c[j];
        for (int i = 1; i <= n; i++) {
            ll a;
            cin >> a;
            town[j].push_back({n + j, i, a});
        }
        sort(town[j].begin(), town[j].end(), cmp);
    }

    // ---------- 第三步：枚举乡镇子集 + 多路归并 Kruskal ----------
    ll ans = LLONG_MAX;

    for (int mask = 0; mask < (1 << k); mask++) {
        ll sum_c = 0;
        vector<int> selected;
        for (int j = 0; j < k; j++) {
            if (mask & (1 << j)) {
                sum_c += c[j + 1];
                selected.push_back(j + 1);
            }
        }
        if (sum_c >= ans) continue;   // 剪枝

        int total_nodes = n + k;
        init_dsu(total_nodes);

        // 多路归并：优先队列存 (边权, u, v, 来源列表ID, 索引)
        // 来源列表ID: -1 表示 base，否则为乡镇编号 j
        struct State {
            ll w;
            int u, v;
            int list_id;
            int idx;
            bool operator>(const State& other) const {
                return w > other.w;
            }
        };
        priority_queue<State, vector<State>, greater<State>> pq;

        if (!base.empty()) {
            pq.push({base[0].w, base[0].u, base[0].v, -1, 0});
        }
        for (int j : selected) {
            if (!town[j].empty()) {
                pq.push({town[j][0].w, town[j][0].u, town[j][0].v, j, 0});
            }
        }

        ll edge_sum = 0;

        while (!pq.empty()) {
            State cur = pq.top();
            pq.pop();

            if (find(cur.u) != find(cur.v)) {
                merge(cur.u, cur.v);
                edge_sum += cur.w;
                if (city_cnt[find(1)] == n) break;  // 所有城市已连通
            }

            // 从同一列表取下一条边
            if (cur.list_id == -1) {
                int ni = cur.idx + 1;
                if (ni < (int)base.size()) {
                    pq.push({base[ni].w, base[ni].u, base[ni].v, -1, ni});
                }
            } else {
                int j = cur.list_id;
                int ni = cur.idx + 1;
                if (ni < (int)town[j].size()) {
                    pq.push({town[j][ni].w, town[j][ni].u, town[j][ni].v, j, ni});
                }
            }
        }

        if (city_cnt[find(1)] == n) {
            ans = min(ans, sum_c + edge_sum);
        }
    }

    cout << ans << endl;
    return 0;
}