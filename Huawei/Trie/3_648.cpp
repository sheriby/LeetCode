#include <bits/stdc++.h>
using namespace std;

struct Trie {
    vector<Trie*> child;
    bool is_end;
    Trie() : child(26, nullptr), is_end(false) {}

    void insert(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) cur->child[idx] = new Trie();
            cur = cur->child[idx];
        }
        cur->is_end = true;
    }

    // 检查单词是否是树中某个单词的前缀,没有的话返回-1，有的话反正前缀的长度
    int check(string word) {
        int res = 0;
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) return -1;
            ++res;
            cur = cur->child[idx];
            if (cur->is_end) return res;
        }
        return -1;
    }
};

class Solution {
   public:
    // 验证单词的前缀是否在树中
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (auto& prefix : dictionary) trie.insert(prefix);
        int len = sentence.size();
        int start = 0;
        string res;
        res.reserve(sentence.size());
        for (int i = 1; i <= len; ++i) {
            if (i == len || sentence[i] == ' ') {
                string tmp = sentence.substr(start, i - start);
                start = i + 1;
                int c = trie.check(tmp);
                if (c == -1)
                    res += tmp;
                else
                    res += tmp.substr(0, c);
                if (i != len) res += " ";
            }
        }
        return res;
    }
};