#include <bits/stdc++.h>
using namespace std;

// 前缀树，又称字典树，可以快速的查询树中是否以给定的单词开头的字符串，即前缀
// 当我们把字符串反转插入的时候，也可以快速查后缀
class Trie {
   public:
    // 26个字母，保存为26个子节点
    vector<Trie*> child;
    // 当前的结点是否是一个单词的结尾
    bool is_end;
    Trie() : child(26, nullptr), is_end(false) {}

    // 插入一个单词
    void insert(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            // 没有当前的子结点
            if (!cur->child[idx]) cur->child[idx] = new Trie();
            cur = cur->child[idx];
        }
        // 将最后一个节点标记为结束
        cur->is_end = true;
    }

    // 是否有当前的单词
    bool search(string word) {
        Trie* cur = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return cur->is_end;
    }

    // 是否有前缀为当前单词的, 和search的唯一区别是不需要验证is_end
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return true;
    }
};