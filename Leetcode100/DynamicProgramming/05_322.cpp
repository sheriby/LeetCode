#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int len = coins.size();
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < len && coins[j] <= i; j++) {
                if (dp[i - coins[j]] != -1) continue;
                if (dp[i] == -1)
                    dp[i] = dp[i - coins[j]] + 1;
                else
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        for (int i = 0; i < amount; i++) {
            if (dp[i] != -1) cout << i << " " << dp[i] << endl;
        }
        return dp[amount];
    }
};