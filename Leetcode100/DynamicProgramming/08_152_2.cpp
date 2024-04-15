#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // dp[i][0] => min product end with i  dp[i][1] => max product end with i
    // min_val, max_val
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int>(2));
        int min_val = nums[0], max_val = nums[0], ans = INT_MIN;
        for (int i = 1; i < len; i++) {
            if (nums[i] > 0) {
                min_val = min(nums[i], min_val * nums[i]);
                max_val = max(nums[i], max_val * nums[i]);
            } else {
                min_val = min(nums[i], max_val * nums[i]);
                max_val = max(nums[i], min_val * nums[i]);
            }
            ans = max(max_val, ans);
        }
        return ans;
    }
};