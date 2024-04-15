#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    // dp[i][i] = true, dp[i][i+1] = s[i] == s[i+1]
    // dp[i][j] = s[i] == s[j] && dp[i+1][j-1]
    // 有关回文串的动态规划问题，很多时候都是通过回文串的长度从大到小来遍历的
    // 如果i+1到j-1是回文串，s[i] == s[j], 那么 i到j就是回文串
    // 这样就从短的回文串状态转移到了长的回文串
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, 0));
        int maxi = 0, max_len = 0;
        for (int i = 0; i < len; ++i) dp[i][i] = true;

        for (int i = 1; i < len; ++i) {
            for (int j = 0; i + j < len; ++j) {
                int e = i + j;
                if (s[j] == s[e] && (e - j < 2 || dp[j + 1][e - 1])) {
                    dp[j][e] = true;
                    if (i > max_len) {
                        max_len = i;
                        maxi = j;
                    }
                }
            }
        }

        return s.substr(maxi, max_len + 1);
    }
};