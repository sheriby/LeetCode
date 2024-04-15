#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // dp(i, j) 标识 word1[0..i] 转换成 word2[0..j] 所需要的最少操作次数
    // if w1(i) == w2(j) dp(i, j) = dp(i - 1, j - 1)
    // else dp(i, j) = min(dp(i - 1, j), dp(i, j - 1), dp(i - 1, j - 1)) + 1
    // dp(i-1, j) 表示增加一个字符, dp(i, j-1) 表示删除一个字符, dp(i-1, j-1)
    // 表示替换一个字符
    // 删除A当中的字符和增加B当中的字符是等价的
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;  // 删除i个字符
        for (int i = 0; i <= n; ++i) dp[0][i] = i;  // 增加i个字符

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] =
                        min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }

        return dp[m][n];
    }
};