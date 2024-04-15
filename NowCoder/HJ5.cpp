#include <bits/stdc++.h>
using namespace std;

inline int hex2num(char ch) {
    if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
    return ch - '0';
}

int main() {
    string hex;
    cin >> hex;
    int res = 0;
    int len = hex.size();
    int base = 1;
    for (int i = len - 1; i >= 2; --i) {
        res += hex2num(hex[i]) * base;
        base *= 16;
    }
    cout << res << endl;

    return 0;
}