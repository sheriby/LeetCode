#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 最多只能完成两笔交易,
    // 可以把原数组分成两个部分啊，这样不就是还原成之前的问题了
    // dp(i, k) + dp(k,len)   k = i...len
    // 这种简单直接的方法，可以通过大部分的测试
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int res = 0;
        for (int i = 0; i < len; ++i) {
            res = max(res, maxProfit(prices, 0, i) + maxProfit(prices, i, len));
        }
        return res;
    }

   private:
    int maxProfit(vector<int>& prices, int s, int e) {
        int res = 0, buy = INT_MAX;
        for (int i = s; i < e; ++i) {
            if (prices[i] < buy)
                buy = prices[i];
            else
                res = max(res, prices[i] - buy);
        }
        return res;
    }
};