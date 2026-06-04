#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int INF = 1e7;
int map[N][N], dist[N], n, m;
int flag[N];
struct Node
{
    int u, step;
    Node() {};
    Node(int a, int sp)
    {
        u = a;
        step = sp;
    }
    bool operator<(const Node &a) const
    { // 重载<
        return step > a.step;
    }
};