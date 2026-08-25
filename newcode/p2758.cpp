#include <bits/stdc++.h>
using namespace std;
const int N = 100;
char str1[N], str2[N];
int d[N][N];
int min(int a, int b)
{
    return a < b ? a : b;
}
int editdistance(char *strl, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0; i <= len1; i++)
        d[i][0] = i;
    for (int j = 0; j <= len2; j++)
        d[0][j] = j;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            int diff;
            if (str1[i - 1] == str2[j - 1])
                diff = 0;
            else
                diff = 1;
            int temp = min(d[i - 1][j] + 1, d[i][j - 1] + 1);
            d[i][j] = min(temp, d[i - 1][j - 1] + diff);
        }
    }
    return d[len1][len2];
}
int main()
{
    cin >> str1;
    cin >> str2;
    cout << editdistance(str1, str2);
    return 0;
}