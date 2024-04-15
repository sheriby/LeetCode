#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strs;
    strs.resize(n);
    for (int i = 0; i < n; ++i) cin >> strs[i];
    sort(strs.begin(), strs.end());
    for (int i = 0; i < strs.size(); ++i) cout << strs[i] << endl;

    return 0;
}