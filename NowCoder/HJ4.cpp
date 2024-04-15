#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;

    while (cin >> str) {
        int len = str.size();
        int i = 0;
        while (i < len) {
            if (i + 8 <= len) {
                cout << str.substr(i, 8) << endl;
                i += 8;
            } else {
                cout << str.substr(i, len - i);
                for (int _ = 0; _ < 8 - len + i; ++_) cout << 0;
                cout << endl;
                break;
            }
        }
    }

    return 0;
}