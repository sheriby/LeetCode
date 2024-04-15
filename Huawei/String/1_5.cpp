#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 回文子串的问题，很多时候都是利用长度进行dp
    // dp[i][i] = true
    // dp[i][i+1] = (s[i] == s[i+1])
    // dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        // 先处理长度为1和2的情况
        for (int i = 0; i < len; ++i) dp[i][i] = true;
        int max_len = 1, start = 0;
        for (int i = 0; i < len - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                max_len = 2;
                start = i;
            }
        }

        for (int i = 2; i < len; ++i) {
            for (int j = 0; j + i < len; ++j) {
                if (s[j] == s[i + j] && dp[j + 1][i + j - 1]) {
                    dp[j][i + j] = true;
                    max_len = i + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};