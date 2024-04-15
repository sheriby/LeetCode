#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    int idx, val;
    for (int i = 0; i < n; ++i) {
        cin >> idx >> val;
        if (mp.count(idx))
            mp[idx] += val;
        else
            mp[idx] = val;
    }

    for (auto& [idx, val] : mp) cout << idx << " " << val << endl;

    return 0;
}