#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<string> mp;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        if (!mp.count(str)) {
            mp.insert(str);
            cout << "#" << str << endl;
        }
    }
    return 0;
}