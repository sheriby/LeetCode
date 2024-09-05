#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    // dp[i]指以第i位结尾符合要求的最长序列的长度
    // dp[i] = max(dp[j]) + 1, j < i, abs(s[i]-s[j])<=k
    int n = s.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(s[i] - s[j]) <= k)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}