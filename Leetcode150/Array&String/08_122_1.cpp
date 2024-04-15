#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // f[i][0] -> max profit without stock
    // f[i][1] -> max profit with stock
    // f[0][0] = 0, f[0][1] = -p[0]
    // f[i+1][0] = max(f[i][0], f[i][1] - p[i] + p[i+1])
    // f[i+1][1] = max(f[i][0] - p[i+1], f[i][1])
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        int f[30001][2];
        f[0][0] = 0;
        f[0][1] = -prices[0];

        for (int i = 1; i < len; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i + 1]);
        }
        return f[len - 1][0];
    }
};