#include <bits/stdc++.h>
using namespace std;

bool check(long long a) {
    string s = to_string(a);
    char base = s[0];
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != base) return false;
    }
    return true;
}

// 从长到短遍历整个字符串，看看其是不是密钥
int main() {
    string str;
    int num;
    char op;
    cin >> str >> num >> op;
    int len = str.size();
    long long pwd = 0;
    for (int i = 12; i > 0; --i) {
        if (pwd) break;
        for (int j = 0; i + j <= len; ++j) {
            long long val = stoll(str.substr(j, i));
            long long after = val;
            switch (op) {
                case '+':
                    after += num;
                    break;
                case '-':
                    after -= num;
                    break;
                case '*':
                    after *= num;
                    break;
            }
            if (check(after)) pwd = max(pwd, val);
        }
    }
    cout << pwd << endl;

    return 0;
}