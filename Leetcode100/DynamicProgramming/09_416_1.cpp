#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    // dp[i][j] 表示 [0,i]中是否有和为j的数
    // dp[i][0] = true 不选
    // dp[0][nums[0]] = true
    // j >= nums[i]; dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]])
    // j < nums[i]; dp[i][j] = dp[i-1][j];
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max_val = *max_element(nums.begin(), nums.end());
        if (sum & 1) return false;
        int target = sum >> 1;
        if (max_val > target) return false;

        vector<vector<bool>> dp(len, vector<bool>(target + 1, false));
        for (int i = 0; i < len; i++) dp[i][0] = true;
        dp[0][nums[0]] = true;
        for (int i = 1; i < len; i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[len - 1][target];
    }
};