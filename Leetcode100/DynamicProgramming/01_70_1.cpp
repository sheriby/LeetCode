#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // dp[n - 1] = 1;
    // dp[n - 2] = 1;
    // dp[n] = dp[n - 1] + dp[n - 2]
    int climbStairs(int n) {
        if (n < 2) return 1;
        vector<int> dp(n, 0);
        dp[n - 1] = 1, dp[n - 2] = 1;
        for (int i = n - 3; i >= 0; i--) {
            dp[i] = dp[i + 1] + dp[i + 2];
        }
        return dp[0];
    }
};