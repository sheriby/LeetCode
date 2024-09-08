#include <bits/stdc++.h>
using namespace std;

char swich(char c) {
    return c == 'A' ? 'B' : 'A';
}

int main() {
    int n;
    string str;
    cin >> n >> str;
    stack<int> stk;
    int max_ans = 100;
    for (int i = 0; i < n; i++) {
        if (stk.empty()) {
            stk.push(str[i]);
            continue;
        }
        if (stk.top() == str[i]) {
            stk.push(str[i]);
            continue;
        }
        int ans = 100;
        int flag = true;
        while (true) {
            if (stk.top() > 100) {
                ans += stk.top() - 100;
                max_ans = max(max_ans, ans);
                stk.pop();
            }
            if (stk.top() == swich(str[i]) && flag) {
                ans += 2;
                max_ans = max(max_ans, ans);
                flag = false;
            }
            if (stk.top() == str[i]) {
                stk.push(ans);
                if (flag) stk.push(str[i]);
                break;
            }
        }
    }
    cout << max_ans - 100 << endl;
    return 0;
}