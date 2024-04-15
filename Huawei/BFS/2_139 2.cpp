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
            if (!cur->child[ch]) return false;
            cur = cur->child[idx];
        }
        return true;
    }

    // 前缀树当中是否有单词word
    bool search(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[ch]) return false;
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }
};

class Solution {
   public:
    // 前缀树可以快速的判读是否beginWith
    // 但是对于这题用遍历来说还是会tle啊
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        int len = wordDict.size();
        for (int i = 0; i < len; ++i) {
            trie.insert(wordDict[i]);
        }
        return wordBreakHelper(s, trie);
    }

   private:
    bool wordBreakHelper(string s, Trie& trie) {
        // int len = s.size();
        // for (int i = 1; i <= len; ++i) {
        //     if (trie.search(s.substr(0, i)) &&
        //         (i == len || wordBreakHelper(s.substr(i), trie)))
        //         return true;
        // }
        // return false;
        return trie.search("leet");
    }
};