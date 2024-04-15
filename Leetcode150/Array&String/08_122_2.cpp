#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // greed
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int res = 0;
        for (int i = 1; i < len; i++) res += max(0, prices[i] - prices[i - 1]);
        return res;
    }
};