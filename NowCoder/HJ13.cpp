#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> strs;
    string str;
    while (cin >> str) strs.push_back(str);

    for (int i = strs.size() - 1; i >= 0; --i) {
        cout << strs[i] << " ";
    }

    return 0;
}