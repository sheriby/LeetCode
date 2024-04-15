#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int visit = 0;
        while (!q.empty()) {
            visit++;
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return visit == numCourses;
    }

   private:
    vector<vector<int>> edges;
    vector<int> indeg;
};