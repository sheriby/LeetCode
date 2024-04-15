#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 朴素的分层BFS，虽然不会TLE，但是运行时间也很长
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = beginWord.size();
        int len = wordList.size();
        unordered_set<string> list_set;
        for (int i = 0; i < len; ++i) list_set.insert(wordList[i]);
        if (!list_set.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        // 从开始的单词开始分层遍历
        int level = 1;
        while (q.size()) {
            int size = q.size();
            for (int _ = 0; _ < size; ++_) {
                string front = q.front();
                q.pop();
                if (front == endWord) return level;
                for (auto it = list_set.begin(); it != list_set.end();) {
                    if (canChange(front, *it)) {
                        q.push(*it);
                        it = list_set.erase(it);
                    } else
                        ++it;
                }
            }
            ++level;
        }
        return 0;
    }

   private:
    bool canChange(string a, string b) {
        int len = a.size();
        int cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) cnt++;
            if (cnt > 1) return false;
        }
        return true;
    }
};