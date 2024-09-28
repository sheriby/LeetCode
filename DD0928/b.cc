#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    bool flag = false;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (flag) {
            flag = false;
            continue;
        }
        if (str[i] == str[i - 1]) {
            ++ans;
            flag = true;
        }
    }
    return 0;
}