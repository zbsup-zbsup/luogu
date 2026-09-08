#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);   // 读整行

    stack<int> st;
    int i = 0;

    while (i < s.size()) {
        if (s[i] >= '0' && s[i] <= '9') {
            int num = 0;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            st.push(num);
        } 
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (s[i] == '+') st.push(a + b);
            else if (s[i] == '-') st.push(a - b);
            else if (s[i] == '*') st.push(a * b);
            else if (s[i] == '/') st.push(a / b);
            i++;
        } 
        else if (s[i] == '@') {
            break;
        } 
        else {
            // 跳过 '.' 等其他字符
            i++;
        }
    }

    cout << st.top() << endl;
    return 0;
}