#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        vector<long long> prefix(n+1, 0);
        long long min_prefix = 0;
        long long max_region = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
            min_prefix = min(min_prefix, prefix[i]);
            max_region = max(max_region, prefix[i] - min_prefix);
        }
        long long anothers = prefix[n] - max_region;
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            max_region = (max_region * 2) % MOD;
            ans = max_region;
        }
        ans = (ans + anothers + MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}