#include <bits/stdc++.h>
using namespace std;

// 检查 a, b, c 三个数是否由 1~9 九个不同的数字组成
bool check(int a, int b, int c) {
    int digits[10] = {0};  // 统计数字出现次数，下标0~9
    // 处理 a
    while (a > 0) {
        digits[a % 10]++;
        a /= 10;
    }
    // 处理 b
    while (b > 0) {
        digits[b % 10]++;
        b /= 10;
    }
    // 处理 c
    while (c > 0) {
        digits[c % 10]++;
        c /= 10;
    }
    // 检查：数字0不能出现，数字1~9必须各出现恰好一次
    if (digits[0] != 0) return false;
    for (int i = 1; i <= 9; i++) {
        if (digits[i] != 1) return false;
    }
    return true;
}

int main() {
    int a = 100, b = 100, c = 100;
    while (a < 1000) {
        while (b < 1000) {
            while (c < 1000) {
                if (a * 2 == b && a * 3 == c) {
                    if (check(a, b, c)) {  // 新增条件判断
                        cout << a << " " << b << " " << c << endl;
                    }
                }
                c++;
            }
            c = 0;
            b++;
        }
        b = 0;
        a++;
    }
    return 0;
}//ac~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~