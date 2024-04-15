#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 暴力遍历，会TLE
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = wordDict.size();
        for (int i = 0; i < len; ++i) {
            if (beginWith(s, wordDict[i]) &&
                (s.size() == wordDict[i].size() ||
                 wordBreak(s.substr(wordDict[i].size()), wordDict))) {
                return true;
            }
        }
        return false;
    }

   private:
    bool beginWith(string s, string word) {
        int slen = s.size(), word_len = word.size();
        if (slen < word_len) return false;
        for (int i = 0; i < word_len; ++i) {
            if (s[i] != word[i]) return false;
        }
        return true;
    }
};