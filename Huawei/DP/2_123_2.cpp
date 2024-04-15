#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // dp(i, k) + dp(k,len)   k = i...len
    // 简单优化一下
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        // dp(0, k) => dp(0, k+1)
        vector<int> dp1(len + 1, 0);
        int res = 0, buy = INT_MAX;
        for (int i = 0; i < len; ++i) {
            if (prices[i] < buy) buy = prices[i];
            res = max(res, prices[i] - buy);
            dp1[i + 1] = res;
        }

        // dp(k+1, len) => dp(k, len)
        res = 0, buy = INT_MAX;
        int max_sell = -1;
        vector<int> dp2(len + 1, 0);
        for (int i = len - 1; i >= 0; --i) {
            if (prices[i] > max_sell) {
                buy = prices[i];
                max_sell = prices[i];
            }
            buy = min(buy, prices[i]);
            res = max(res, max_sell - buy);
            dp2[i + 1] = res;
        }

        int max_pro = 0;

        for (int i = 0; i <= len; ++i) {
            max_pro = max(max_pro, dp1[i] + dp2[i]);
        }
        return max_pro;
    }
};