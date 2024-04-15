#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 如果一个单词是另一个单词的后缀，那么直接把这个单词去除就行了
    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size();
        unordered_set<string> word_set;
        for (int i = 0; i < len; ++i) word_set.insert(words[i]);

        for (int i = 0; i < len; ++i) {
            for (int j = 1; j < words[i].size(); ++j) {
                // 去除所有的有相同后缀的单词
                word_set.erase(words[i].substr(j));
            }
        }

        int ans = 0;
        // 每个单词加上#的长度
        for (auto word : word_set) ans += word.size() + 1;

        return ans;
    }
};