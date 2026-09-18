#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4000005;
const int MAXS = 8000005;
bool is_sq[MAXS];
int rest[MAXN];
int temp[MAXN];
int ans[MAXN];

int main()
{
    // 预处理
    for (int i = 1; i * i <= 8000000; i++)
    {
        is_sq[i * i] = true;
    }

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "1" << endl;
            continue;
        }
        int top = 0;
        for (int i = 2; i <= n; i++)
        {
            rest[top++] = i;
        }

        int ans_cnt = 0;
        ans[ans_cnt++] = 1;
        int cur = 1;

        while (top > 0)
        {
            int temp_cnt = 0;
            int y = -1;
            while (top > 0)
            {
                int cand = rest[top - 1];
                if (!is_sq[cur + cand])
                {
                    y = cand;
                    top--;
                    break;
                }
                else
                {
                    top--;
                    temp[temp_cnt++] = cand; // 冲突，暂存
                }
            }
            ans[ans_cnt++] = y;
            cur = y;
            for (int i = temp_cnt - 1; i >= 0; i--)
            {
                rest[top++] = temp[i];
            }
        }

        for (int i = 0; i < ans_cnt; i++)
        {
            cout << ans[i]<<' ';
        }
        cout << endl;
    }
    return 0;
}