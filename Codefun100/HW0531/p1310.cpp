#include <bits/stdc++.h>
using namespace std;

// dp[i][j] => min(dp[i-2][j] + dp[i][j-2] + 1, ...)
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = i * j;
            for (int k = 2; i - k >= 0 && j - k >= 0; k++)
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[i][j - k] + 1);
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}