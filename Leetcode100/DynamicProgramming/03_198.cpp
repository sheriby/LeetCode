#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // dp[i][0] => not steal from house i
    // dp[i][1] => steal from house i
    // dp[i + 1][0] = max(dp[i][0], dp[i][1])
    // dp[i + 1][1] = dp[i][0] + nums[i]
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int>(2, 0));
        for (int i = 1; i <= len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }
        return max(dp[len][0], dp[len][1]);
    }
};