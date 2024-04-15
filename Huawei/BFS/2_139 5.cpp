#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 同样的也可以使用BFS来解决该题
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> vis(len + 1, false);
        unordered_set<string> word_set;
        for (int i = 0; i < wordDict.size(); ++i) word_set.insert(wordDict[i]);
        queue<int> q;

        q.push(0);
        while (q.size()) {
            int front = q.front();
            q.pop();
            if (front == len) return true;
            // 记录访问过的位置，不再多次访问
            if (vis[front]) continue;
            vis[front] = true;

            for (int i = front; i < len; ++i) {
                if (!vis[i + 1] &&
                    word_set.count(s.substr(front, i - front + 1))) {
                    q.push(i + 1);
                }
            }
        }
        return false;
    }
};