#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// >时候
// dp[i][j] = dp[i-1][j-1];
// dp[0][j] = j;

int main() {
    int n, k;
    string ops;
    int res = 0;
    cin >> n >> k;
    cin >> ops;
    vector<vector<int>> dp(n, vector<int>(k, 0));
    for (int i = 1; i <= k; ++i) dp[0][i] = 1;

    for (int i = 1; i < n; ++i) {
        char op = ops[i - 1];
        for (int j = 1; j <= k; ++j) {
            switch (op) {
                case '=':
                    dp[i][j] = dp[i - 1][j];
                    break;
                case '<':
                    for (int m = 1; m < j; m++) {
                        dp[i][j] += dp[i - 1][m];
                        dp[i][j] %= MOD;
                    }
                    break;
                case '>':
                    for (int m = j + 1; m <= k; m++) {
                        dp[i][j] += dp[i - 1][m];
                        dp[i][j] %= MOD;
                    }
                    break;
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        res += dp[n - 1][i];
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}