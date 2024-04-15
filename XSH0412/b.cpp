#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) cin >> nums[i];
    vector<vector<int>> dp(x + 1, vector<int>(2, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = x; j >= nums[i] / 2; --j) {
            // 没有使用额外的那次转发
            dp[j][0] = min(dp[j][0], dp[j - nums[i] / 2][0] + 1);
            // 之前使用过那次额外的转发
            dp[j][1] = min(dp[j][1], dp[j - nums[i] / 2][1] + 1);
            // 本次使用这次额外的转发
            if (j >= nums[i]) dp[j][1] = min(dp[j][1], dp[j - nums[i]][0] + 1);
        }
    }
    int res = min(dp[x][0], dp[x][1]);
    if (res == INF)
        cout << -1 << endl;
    else
        cout << res << endl;

    return 0;
}