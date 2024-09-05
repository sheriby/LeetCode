#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
    // dp(i, 0) => 删
    // dp(i, 1) => 不删
    // dp(i, 0) => dp(i-1, 1) + v(i)
    // dp(i, 1) => max(dp(i-1, 0), dp(i-1, 1))

    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i-1] + 1) {
            // 主要考虑相邻的情况
            // 删了需要前一个没被删，但是不删前面一个可删也可以不删
            dp[i][0] = dp[i-1][1] + arr[i];
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        } else {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + arr[i];
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    return 0;
}