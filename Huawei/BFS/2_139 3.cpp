#include <bits/stdc++.h>
using namespace std;

struct Trie {
    vector<Trie*> child;
    bool isEnd;
    Trie() : child(26, nullptr), isEnd(false) {}

    // 将一个字符串加入前缀树当中
    void insert(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) cur->child[idx] = new Trie();
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }

    // 前缀树当中是否有以word开头的单词
    bool beginWith(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return true;
    }

    // 前缀树当中是否有单词word
    bool search(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }
};

class Solution {
   public:
    // 得结合前缀树和动态规划来做
    // dp[i] => 表示 [0, i)的字符串能否表示
    // dp[j] => dp[i] && search(i, j)
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        int len = s.size();
        for (int i = 0; i < wordDict.size(); ++i) trie.insert(wordDict[i]);
        vector<bool> dp(len + 1, false);
        dp[0] = true;  // 空字符串可以表示
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && trie.search(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};