#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 10,9,2,5,3,7,101,18
    // dp[i] max length end with nums[i]
    // dp[i+1] = if nums[i] > nums[j] then dp[i+1] = dp[j] + 1
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = 1;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
