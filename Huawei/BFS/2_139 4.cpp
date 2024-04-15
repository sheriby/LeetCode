#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 没有用到前缀树的startwith功能，只用到了search，和前缀树有点不相干了，可以直接用hashset来查找
    // 使用DFS+记忆化搜索
    bool wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); ++i) word_set.insert(wordDict[i]);
        return dfs(s, 0);
    }

   private:
    unordered_map<int, bool> mem;
    unordered_set<string> word_set;
    // [s, len)是否可以表示
    bool dfs(string s, int idx) {
        int len = s.size();
        if (idx == len) return true;

        // 有记忆了，直接返回
        if (mem.count(idx)) return mem[idx];

        for (int i = idx; i < len; ++i) {
            if (word_set.count(s.substr(idx, i - idx + 1)) && dfs(s, i + 1)) {
                // 记忆存储
                mem[i] = true;
                return true;
            }
        }
        // 记忆存储
        mem[idx] = false;
        return false;
    }
};