#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 用dfs和bfs都可以，感觉用dfs更好点，从边界的O开始
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (!vis[i][n - 1] && board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[0][i] && board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (!vis[m - 1][i] && board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }

   private:
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<bool>> vis;
    // 从边界的0出发dfs, vis过的都是合理的0
    void dfs(vector<vector<char>>& board, int x, int y) {
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= m || newy < 0 || newy >= n) continue;
            if (!vis[newx][newy] && board[newx][newy] == 'O') {
                dfs(board, newx, newy);
            }
        }
    }
};