#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
struct node
{
    long long x;
    int y;
} a[maxn];
int m, tot, cnt, f[maxn];
long long d, t, x, num[maxn];
char ch[3];
int find(int x)
{
    if (x != f[x])
        f[x] = find(f[x]);
    return f[x];
}
int main()
{
    cin >> m >> d;
    for (int i = 1; i <= m; i++)
    {
        getchar();
        cin>>ch;
        cin>>x;
        if (ch[0] == 'A')
        {
            x += t;
            x %= d;
            tot++;
            num[tot] = x;
            f[tot] = tot;
            while (x > a[cnt].x && cnt)
            {
                f[a[cnt].y] = tot;
                cnt--;
            }
            a[++cnt].x = x;
            a[cnt].y = tot;
        }
        else
        {
            x = tot - x + 1;
            int y = find(x);
            t = num[y];
            cout<<t;
        }
    }
    return 0;
}
