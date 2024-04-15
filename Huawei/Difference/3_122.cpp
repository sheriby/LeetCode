#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // dp[i][0] max profit without stock on day i
    // dp[i][1] max profit with stock on day i
    // 前一天没股票，或者股票今天卖了
    // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + p[i])
    // 前一天有股票，或者今天买了
    // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - p[i])
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[len - 1][0];  // 最大利润肯定是最后一天没股票
    }
};