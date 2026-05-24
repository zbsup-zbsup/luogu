#include <bits/stdc++.h>//ac
using namespace std;
#include <string>
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int reverted = 0;
    while (x > reverted)
    {
        reverted = reverted * 10 + x % 10;
        x /= 10;
    }
    return x == reverted || x == reverted / 10;
}
void work(int sw, int ew)
{

    for (int i = sw; i <= ew; i++)
    {
        if (isPalindrome(i))
        {
            if (isPrime(i))
                cout << i << endl;
        }
    }
    return;
}
int main()
{
    int s, e;
    cin >> s >> e;
    work(s, e);
    return 0;
}//已通过