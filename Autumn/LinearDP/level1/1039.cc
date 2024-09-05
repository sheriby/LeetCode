#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> height(n);
    for (int i = 0; i < n; ++i) cin >> height[i];
    // dp[i] = min(dp[j] + cost(i->j)), j - i <= k
    vector<int> dp(n, 0x7fffffff);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j < 0) break;
            dp[i] = min(dp[i], dp[i - j] + max(0, height[i] - height[i-j]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}