#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // dp[i][0] => min product end with i  dp[i][1] => max product end with i
    // nums[i] > 0, dp[i][0] = min(nums[i], dp[i - 1][0] * nums[i])
    //              dp[i][1] = max(nums[i], dp[i - 1][1] * nums[i])
    // nums[i] < 0, dp[i][0] = min(nums[i], dp[i - 1][1] * nums[i])
    //              dp[i][1] = max(nums[i], dp[i - 1][0] * nums[i])
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int>(2));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for (int i = 1; i < len; i++) {
            if (nums[i] > 0) {
                dp[i][0] = min(nums[i], dp[i - 1][0] * nums[i]);
                dp[i][1] = max(nums[i], dp[i - 1][1] * nums[i]);
            } else {
                dp[i][0] = min(nums[i], dp[i - 1][1] * nums[i]);
                dp[i][1] = max(nums[i], dp[i - 1][0] * nums[i]);
            }
        }
        int max = INT_MIN;
        for (int i = 0; i < len; i++) {
            if (max < dp[i][1]) max = dp[i][1];
        }
        return max;
    }
};