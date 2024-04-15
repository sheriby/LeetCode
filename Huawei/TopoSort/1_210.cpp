#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 拓扑排序用于有向无环图可以给出一种合理的任务调度的顺序，同时也可以检测有向图是否存在环
    // 对于无向图是否有环的判断，可以使用拓扑排序也可以使用并查集
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inedges(numCourses, 0);
        vector<int> res;
        res.reserve(numCourses);
        // 计算入度
        for (auto& prerequisite : prerequisites) {
            // 有向图 prerequisite[1] -> prerequisite[0]
            inedges[prerequisite[0]]++;
        }

        // 入度为0的结点进队列
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!inedges[i]) q.push(i);
        }

        while (q.size()) {
            int course = q.front();
            res.push_back(course);
            q.pop();
            // 出队列的时候，讲相邻的结点入度-1，如果此时遇到入度为0的结点，继续入队列
            for (auto& prerequisite : prerequisites) {
                if (prerequisite[1] == course) {
                    inedges[prerequisite[0]]--;
                    if (!inedges[prerequisite[0]]) q.push(prerequisite[0]);
                }
            }
        }
        // 有足够的结点说明无环，没有足够的结点说明有环
        return res.size() == numCourses ? res : vector<int>();
    }
};