#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // dp[n] = 0
    // dp[i] = min(dp[i~i+n[i]])+1
    int jump(vector<int>& nums) {
        int len = nums.size();
        int dp[10001];
        fill(dp, dp + len, 0x7ffffffe);
        dp[len - 1] = 0;
        for (int i = len - 2; i >= 0; i--)
            for (int j = 1; j <= nums[i] && i + j < len; j++)
                dp[i] = min(dp[i], dp[i + j] + 1);
        return dp[0];
    }
};