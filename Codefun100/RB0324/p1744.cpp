#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) cin >> nums[i];

    vector<vector<int>> dp(x + 1, vector<int>(2, 0x3f3f));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = x; j >= nums[i] / 2; j--) {
            // dp[j][0] 表示没有那多次推荐的那次机会用掉
            dp[j][0] = min(dp[j][0], dp[j - (nums[i] / 2)][0] + 1);
            // 在之前用的多次推荐机会
            dp[j][1] = min(dp[j][1], dp[j - (nums[i] / 2)][1] + 1);
            // 在此时用这个多次推荐机会
            if (j >= nums[i]) dp[j][1] = min(dp[j][1], dp[j - nums[i]][0] + 1);
        }
    }
    // 也可能不用这个多次推荐的机会
    int res = min(dp[x][0], dp[x][1]);
    cout << ((res == 0x3f3f) ? -1 : res) << endl;
    return 0;
}