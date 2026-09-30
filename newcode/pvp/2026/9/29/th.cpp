#include <bits/stdc++.h>
using namespace std;

// 方向编号：0=U, 1=D, 2=L, 3=R
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// 左转、右转、'/' 镜子、'\' 镜子的出射方向映射
int lt[4]        = {2, 3, 1, 0}; // U->L, D->R, L->D, R->U
int rt[4]       = {3, 2, 0, 1}; // U->R, D->L, L->U, R->D
int mirrorSlash[4]     = {3, 2, 1, 0}; // '/' : U->R, D->L, L->D, R->U
int mirrorBackslash[4] = {2, 3, 0, 1}; // '\' : U->L, D->R, L->U, R->D

struct state 
{
    int r, c, dir_in;
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    char d1, d2;
    int p1, p2;
    cin >> d1 >> p1 >> d2 >> p2;

    // 起点：光线进入的第一个格子和进入方向
    int sr, sc, sdir;
    if (d1 == 'U')      { sr = 0;     sc = p1 - 1; sdir = 1; } // 向下进入
    else if (d1 == 'D') { sr = n - 1; sc = p1 - 1; sdir = 0; } // 向上进入
    else if (d1 == 'L') { sr = p1 - 1; sc = 0;     sdir = 3; } // 向右进入
    else                { sr = p1 - 1; sc = m - 1; sdir = 2; } // 向左进入

    int total = n * m;
    vector<array<bool, 4>> visited(total);
    for (auto &v : visited) v.fill(false);

    vector<array<state, 4>> parent(total);
    vector<array<int, 4>>   outDir(total);
    for (auto &v : outDir) v.fill(-1);

    visited[sr * m + sc][sdir] = true;
    parent[sr * m + sc][sdir] = {-1, -1, -1};

    queue<state> q;
    q.push({sr, sc, sdir});

    bool found = false;
    state endState = {-1, -1, -1};

    while (!q.empty() && !found) {
        state cur = q.front(); q.pop();
        int r = cur.r, c = cur.c, dir_in = cur.dir_in;
        char cell = g[r][c];

        // 当前格子允许的出射方向
        int outs[3];
        int numOuts = 0;
        if (cell == '/') {
            outs[numOuts++] = mirrorSlash[dir_in];
        } else if (cell == '\\') {
            outs[numOuts++] = mirrorBackslash[dir_in];
        } else { // '.'
            outs[numOuts++] = dir_in;          // 直行
            outs[numOuts++] = lt[dir_in]; // 左转
            outs[numOuts++] = rt[dir_in];// 右转
        }

        for (int k = 0; k < numOuts; k++) {
            int dir_out = outs[k];
            int nr = r + dr[dir_out];
            int nc = c + dc[dir_out];

            bool out = false, match = false;
            if (nr < 0) {
                out = true;
                if (d2 == 'U' && p2 == c + 1) match = true;
            } else if (nr >= n) {
                out = true;
                if (d2 == 'D' && p2 == c + 1) match = true;
            } else if (nc < 0) {
                out = true;
                if (d2 == 'L' && p2 == r + 1) match = true;
            } else if (nc >= m) {
                out = true;
                if (d2 == 'R' && p2 == r + 1) match = true;
            }

            if (out) {
                if (match) {
                    found = true;
                    endState = cur;
                    outDir[r * m + c][dir_in] = dir_out;
                    break;
                }
                continue;
            }

            if (!visited[nr * m + nc][dir_out]) {
                visited[nr * m + nc][dir_out] = true;
                parent[nr * m + nc][dir_out] = cur;
                outDir[r * m + c][dir_in] = dir_out;
                q.push({nr, nc, dir_out});
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // 回溯路径
    vector<state> path;
    state cur = endState;
    while (cur.r != -1) {
        path.push_back(cur);
        cur = parent[cur.r * m + cur.c][cur.dir_in];
    }
    reverse(path.begin(), path.end());

    // 根据路径修改空格子
    for (auto &s : path) {
        int r = s.r, c = s.c, dir_in = s.dir_in;
        if (g[r][c] != '.') continue; // 固定镜子不动
        int dir_out = outDir[r * m + c][dir_in];
        if (dir_out == dir_in) {
            // 直行，保持 '.'
        } else if (dir_out == mirrorSlash[dir_in]) {
            g[r][c] = '/';
        } else {
            g[r][c] = '\\';
        }
    }

    for (int i = 0; i < n; i++) {
        cout << g[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}