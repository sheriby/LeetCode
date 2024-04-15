#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int res = 0, buy = INT_MAX;
        for (int i = 0; i < len; ++i) {
            if (prices[i] < buy)
                buy = prices[i];
            else
                res = max(res, prices[i] - buy);
        }
        return res;
    }
};