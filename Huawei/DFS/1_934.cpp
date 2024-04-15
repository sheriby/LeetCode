#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
class Solution {
   public:
    // 两个岛成桥的最短的桥
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vis = vector<vector<bool>>(n, vector<bool>(n, false));
        int x, y;
        // 将一个岛标记为2
        for (int i = 0; i < n; ++i) {
            int flag = false;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    x = i, y = j;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        queue<PII> q;
        mark(grid, x, y, q);
        // 从2找1最近的距离 计算距离这种事情一般都是用BFS
        // 将所有的2都放入到队列当中 !!!
        int step = 0;
        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if (newx < 0 || newx >= n || newy < 0 || newy >= n)
                        continue;
                    if (grid[newx][newy] == 0) {
                        q.push({newx, newy});
                        grid[newx][newy] = 2;
                    } else if (grid[newx][newy] == 1)
                        return step;
                }
            }
            step++;
        }
        return -1;
    }

   private:
    int n;
    vector<vector<bool>> vis;
    unordered_map<int, int> mp;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void mark(vector<vector<int>>& grid, int x, int y, queue<PII>& q) {
        grid[x][y] = 2;
        vis[x][y] = true;
        q.push({x, y});
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= n || newy < 0 || newy >= n ||
                vis[newx][newy] || grid[newx][newy] != 1)
                continue;
            mark(grid, newx, newy, q);
        }
    }
};