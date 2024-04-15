#include <bits/stdc++.h>
using namespace std;

struct Trie {
    vector<Trie*> child;
    bool isEnd;
    Trie() : child(26, nullptr), isEnd(false) {}

    void insert(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) cur->child[idx] = new Trie();
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }

    bool beginWith(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return true;
    }

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
    // 前缀树只能查前缀，但是我们把单词反转过来，那么后缀不就是前缀了嘛
    // time me => emit em
    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size();
        // 将每个单词反转
        for (auto& word : words) reverse(word.begin(), word.end());
        // 按照单词的长短排序
        sort(words.begin(), words.end(),
             [](auto& a, auto& b) { return a.size() > b.size(); });

        int ans = 0;
        Trie trie;
        for (auto& word : words) {
            if (trie.beginWith(word)) continue;
            trie.insert(word);
            ans += word.size() + 1;
        }

        return ans;
    }
};