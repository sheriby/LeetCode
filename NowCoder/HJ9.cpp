#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.size();
    vector<int> mp(10, 0);
    char last = -1;
    for (int i = len - 1; i >= 0; --i) {
        if (!mp[str[i] - '0']) {
            ++mp[str[i] - '0'];
            cout << str[i];
        }
    }
    cout << endl;

    return 0;
}