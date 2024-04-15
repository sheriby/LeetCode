#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;

        int vis[12][12] = {0};
        for (int i = 0; i <= m; i++) {
            vis[i][0] = 1;
            vis[i][n + 1] = 1;
        }
        for (int i = 0; i <= n; i++) {
            vis[0][i] = 1;
            vis[m + 1][i] = 1;
        }

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = 0;

        int x = 1, y = 1;
        while (true) {
            res.push_back(matrix[x - 1][y - 1]);
            vis[x][y] = 1;
            if (res.size() == m * n) break;

            int nextx = x + dx[dir];
            int nexty = y + dy[dir];
            if (vis[nextx][nexty]) {
                dir = (dir + 1) % 4;
                nextx = x + dx[dir];
                nexty = y + dy[dir];
            }
            x = nextx;
            y = nexty;
        }

        return res;
    }
};