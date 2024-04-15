#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 7 1 5 3 6 4
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        int res = 0;
        int buy = -1;
        for (int i = 0; i < len; i++) {
            if (buy == -1)
                buy = prices[i];
            else if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] > buy) {
                res = max(res, prices[i] - buy);
            }
        }
        return res;
    }
};