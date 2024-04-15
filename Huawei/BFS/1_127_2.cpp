#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 当BFS的终点和起点都知道的时候，可以使用双向的BFS来优化
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = beginWord.size();
        int len = wordList.size();
        unordered_set<string> list_set;
        // 使用两个set来分别存储两个方向的遍历的节点
        unordered_set<string> start_vis;
        unordered_set<string> end_vis;
        int flag = false;
        for (int i = 0; i < len; ++i) {
            if (wordList[i] == endWord) {
                flag = true;
                break;
            }
        }
        if (!flag) return 0;

        // 使用两个队列来维护双向的BFS遍历
        queue<string> qs, qe;
        qs.push(beginWord);
        qe.push(endWord);
        start_vis.insert(beginWord);
        end_vis.insert(endWord);

        int level = 1;
        while (qs.size() && qe.size()) {
            // 每次使用队列当中更少的元素进行扩散
            if (qs.size() > qe.size()) {
                swap(qs, qe);
                swap(start_vis, end_vis);
            }
            // 一层一层的遍历
            int size = qs.size();
            for (int _ = 0; _ < size; ++_) {
                string front = qs.front();
                qs.pop();

                for (int i = 0; i < len; ++i) {
                    if (!start_vis.count(wordList[i]) &&
                        canChange(front, wordList[i])) {
                        // 双向的BFS，少算了一次从终点的步数，所以这里要返回level+1
                        if (end_vis.count(wordList[i])) return level + 1;
                        qs.push(wordList[i]);
                        start_vis.insert(wordList[i]);
                    }
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