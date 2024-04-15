#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 依旧还是dp(i, j) = dp(i-1, j) + dp(i, j-1)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                if (i > 0 && obstacleGrid[i - 1][j] != 1)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0 && obstacleGrid[i][j - 1] != 1)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};