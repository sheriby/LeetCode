#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
class Solution {
   public:
    // dfs和bfs应该都行，这里用bfs
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        int cnt = nearBoom(board, x, y);
        if (cnt > 0) {
            board[x][y] = '0' + cnt;
            return board;
        }
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<PII> q;
        q.push({x, y});
        while (q.size()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            // 使用BFS的时候千万要注意vis的重复访问的问题
            if (vis[x][y]) continue;
            vis[x][y] = true;
            board[x][y] = 'B';

            for (int i = 0; i < 8; ++i) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx < 0 || newx >= m || newy < 0 || newy >= n ||
                    board[newx][newy] != 'E' || vis[newx][newy])
                    continue;
                int booms = nearBoom(board, newx, newy);
                if (booms == 0)
                    q.push({newx, newy});
                else
                    board[newx][newy] = '0' + booms;
            }
        }
        return board;
    }

   private:
    int m, n;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int nearBoom(vector<vector<char>>& board, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= m || newy < 0 || newy >= n) continue;
            if (board[newx][newy] == 'M') ++cnt;
        }
        return cnt;
    }
};