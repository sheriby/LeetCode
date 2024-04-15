#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int min_val = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                min_val = min(min_val, dp[i - j * j]);
            }
            dp[i] = min_val + 1;
        }

        return dp[n];
    }
};
