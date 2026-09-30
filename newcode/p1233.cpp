#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
struct datat
{
    int l, w;
};
bool cmp(datat a, datat b)
{
    return a.l > b.l; // big->small (>)
}

bool cmpw(datat a, datat b)
{
    return a.w > b.w;
}

int main()
{
    int n;
    cin >> n;
    vector<datat> wood(n);
    int ll, ww;
    for (int i = 0; i < n; i++)
    {
        cin >> ll >> ww;
        wood[i].l = ll;
        wood[i].w = ww;
    }

    sort(wood.begin(), wood.end(), cmp);

    int left = 0;
    for (int i = 1; i < n; i++)
    {
        if (wood[left].l == wood[i].l) // 是否相同
        {
            continue;
        }
        else
        {
            if (left == (i - 1))
            {
                left = i;
                continue;
            }
            else
            {
                sort(wood.begin() + left, wood.begin() + i, cmpw);
                left = i;
            }
        }
    }
    if (left < n - 1)
    {
        sort(wood.begin() + left, wood.end(), cmpw);
    }


    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound(wood[i].w); 
        if (it != s.end())
            s.erase(it);
        s.insert(wood[i].w);
    }


    cout << s.size();
    return 0;
}