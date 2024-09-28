#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<int> _set(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        _set.insert(x);
    }
    int ans = 0;
    for (int i = 0; i <= m; ++i) {
        if (_set.find(i) == _set.end()) {
            ans++;
            m -= i;
        }
    }
    cout << ans << endl;
    return 0;
}