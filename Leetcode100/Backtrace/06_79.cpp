#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 1)) return true;
                }
            }
        }
        return false;
    }

   private:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int visit[10][10];
    bool dfs(vector<vector<char>>& board, int x, int y, string& word,
             int index) {
        visit[x][y] = 1;
        if (index == word.size()) return true;
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                !visit[newX][newY] && board[newX][newY] == word[index]) {
                visit[newX][newY] = 1;
                if (dfs(board, newX, newY, word, index + 1)) return true;
                visit[newX][newY] = 0;
            }
        }
        visit[x][y] = 0;
        return false;
    }
};