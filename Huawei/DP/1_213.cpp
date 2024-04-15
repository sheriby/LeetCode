#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // dp(i,0) => not steal, dp(i, 1) => steal
    // dp(i,0) = max(dp(i-1,1), dp(i-1, 0))
    // dp(i,1) = dp(i-1, 0) + p[i]
    // 队头和队尾是相连接的，除非数组的长度为1
    // 问题的难点在于1和len不能同时偷
    // 可以将问题转为为偷1~len-1和偷2~len这两个区间哪个偷的更多
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        int res1, res2;
        vector<vector<int>> dp(len + 1, vector<int>(2, 0));
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }
        res1 = max(dp[len - 1][0], dp[len - 1][1]);
        dp = vector<vector<int>>(len + 1, vector<int>(2, 0));
        for (int i = 2; i <= len; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }
        res2 = max(dp[len][0], dp[len][1]);
        return max(res1, res2);
    }
};