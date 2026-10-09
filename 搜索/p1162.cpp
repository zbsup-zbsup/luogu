#include <bits/stdc++.h>
using namespace std;
short fz[40][40];
bool yxcin = 0;
queue<short> shunxu;
short fzw[40][40];
// int hzts=3;//行状态数  3代表没有1   2代表有1但不允许放入0     1代表合法
void work()
{
    int x, y;
    while (!shunxu.empty())
    {
        x = shunxu.front();
        shunxu.pop();
        y = shunxu.front();
        shunxu.pop();
        fz[x][y] = 2;
        if (fz[x - 1][y] == 0) // 左移一位
        {
            if (fzw[x - 1][y] == 0)
            {
                shunxu.push(x - 1); // 先压x再压y
                shunxu.push(y);
                fzw[x - 1][y] = 1;
            }
        }
        if (fz[x + 1][y] == 0) // 右移一位
        {
            if (fzw[x + 1][y] == 0)
            {
                shunxu.push(x + 1);
                shunxu.push(y);
                fzw[x + 1][y] = 1;
            }
        }
        if (fz[x][y - 1] == 0) // 下移一位
        {
            if (fzw[x][y - 1] == 0)
            {
                shunxu.push(x);
                shunxu.push(y - 1);
                fzw[x][y - 1] = 1;
            }
        }
        if (fz[x][y + 1] == 0) // up
        {
            if (fzw[x][y + 1] == 0)
            {
                shunxu.push(x);
                shunxu.push(y + 1);
                fzw[x][y + 1] = 1;
            }
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> fz[i][j];
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fz[i][j] == 1)
                if (fz[i + 1][j] == 0)
                {
                    shunxu.push(i + 1);
                    shunxu.push(j);
                    yxcin = 1;
                    work();
                    break;
                }
        }
        if (yxcin)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << fz[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
} // code by clrain
//总算是过了，这里最主要一点就是要注意去重，一直mle快自闭了