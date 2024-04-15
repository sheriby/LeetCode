#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visit.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visit[i] && valid) {
                dfs(i);
            }
        }
        return valid;
    }

   private:
    vector<vector<int>> edges;
    vector<int> visit;
    bool valid = true;

    void dfs(int u) {
        visit[u] = 1;
        for (int v : edges[u]) {
            if (!visit[v]) {
                dfs(v);
                if (!valid) return;
            } else if (visit[v] == 1) {
                valid = false;
                return;
            }
        }
        visit[u] = 2;
    }
};