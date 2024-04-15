#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

inline int mod_plus(int x, int y) { return (x + y) % MOD; }
inline int mod_minus(int x, int y) { return (x - y + MOD) % MOD; }

// dp数组的前缀和优化
int main() {
    int n, k;
    string ops;
    int res = 0;
    cin >> n >> k;
    cin >> ops;
    vector<vector<int>> dp(n, vector<int>(k, 0));
    vector<vector<int>> dp_presum(n, vector<int>(k, 0));
    for (int i = 1; i <= k; ++i) dp[0][i] = 1;
    for (int i = 1; i <= k; ++i)
        dp_presum[0][i] = mod_plus(dp_presum[0][i - 1], dp[0][i]);

    for (int i = 1; i < n; ++i) {
        char op = ops[i - 1];
        for (int j = 1; j <= k; ++j) {
            switch (op) {
                case '=':
                    dp[i][j] = dp[i - 1][j];
                    break;
                case '<':
                    dp[i][j] = dp_presum[i - 1][j - 1];
                    break;
                case '>':
                    // 注意，这里因为两个数都取了mod，所以可以会导致前面大的数取完mod会变小，所以相减需要+mod
                    dp[i][j] =
                        mod_minus(dp_presum[i - 1][k], dp_presum[i - 1][j]);
                    break;
            }
            dp_presum[i][j] = mod_plus(dp_presum[i][j - 1], dp[i][j]);
        }
    }
    for (int i = 1; i <= k; ++i) {
        res += dp[n - 1][i];
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}