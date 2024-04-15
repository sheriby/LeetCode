#include <bits/stdc++.h>
using namespace std;

struct Trie {
    vector<Trie*> child;
    bool isEnd;
    int child_size = 0;
    Trie() : child(26, nullptr), isEnd(false) {}

    Trie* insert(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) cur->child[idx] = new Trie();
            cur->child_size++;
            cur = cur->child[idx];
        }
        cur->isEnd = true;
        return cur;
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
    // 本题当中的前缀树还可以做特殊的优化，即找到所有的叶子节点的结束字符串就行了，不用排序
    // 每次insert的时候都会返回最后一个节点
    // 使用hashmap维护最后一个节点和原字符串之间的联系
    // 在前缀树中保存子节点的数量
    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size();
        // 将每个单词反转
        for (auto& word : words) reverse(word.begin(), word.end());

        int ans = 0;
        Trie trie;
        unordered_map<Trie*, int> mp;
        for (int i = 0; i < len; ++i) {
            Trie* node = trie.insert(words[i]);
            mp[node] = i;
        }

        for (auto& [node, idx] : mp) {
            if (node->child.size() == 0) ans += words[idx].size() + 1;
        }

        return ans;
    }
};