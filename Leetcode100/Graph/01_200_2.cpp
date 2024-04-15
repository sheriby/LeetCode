#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }

   private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void bfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = row + dx[i];
                int newY = col + dy[i];
                if (newX >= 0 && newX < grid.size() && newY >= 0 &&
                    newY < grid[0].size() && grid[newX][newY] == '1') {
                    grid[newX][newY] = '0';
                    q.push({newX, newY});
                }
            }
        }
    }
};
