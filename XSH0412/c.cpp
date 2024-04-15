#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
inline int mod_plus(int x, int y) { return (x + y) % MOD; }
inline int mod_minus(int x, int y) { return (x - y + MOD) % MOD; }

int main() {
    int n, m;
    string ops;
    cin >> n >> m >> ops;
    // dp[i][j] 表示只看前i个数，第i个数分享数j时的最多的可能的结果
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    // 使用前缀和优化求和步骤
    vector<vector<int>> dp_presum(n, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; ++i) dp[0][i] = 1;
    for (int i = 1; i <= m; ++i)
        dp_presum[0][i] = mod_plus(dp_presum[0][i - 1], dp[0][i]);

    for (int i = 1; i < n; ++i) {
        char op = ops[i - 1];
        for (int j = 1; j <= m; ++j) {
            if (op == '=')
                dp[i][j] = dp[i - 1][j];
            else if (op == '<')
                dp[i][j] = dp_presum[i - 1][j - 1];
            else if (op == '>')
                dp[i][j] = mod_minus(dp_presum[i - 1][m], dp_presum[i - 1][j]);

            dp_presum[i][j] = mod_plus(dp_presum[i][j - 1], dp[i][j]);
        }
    }

    int res = 0;
    for (int i = 1; i <= m; ++i) res = mod_plus(res, dp[n - 1][i]);
    cout << res << endl;

    return 0;
}