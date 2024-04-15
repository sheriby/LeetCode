#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        return dfs(0, 0, target, matrix);
    }

   private:
    int m, n;

    bool dfs(int x, int y, int target, vector<vector<int>>& matrix) {
        if (matrix[x][y] == target ||
            (x + 1 < m && matrix[x + 1][y] == target) ||
            (y + 1 < n && matrix[x][y + 1] == target))
            return true;
        bool down = false;
        if (x + 1 < m && matrix[x + 1][y] < target)
            down = dfs(x + 1, y, target, matrix);
        bool right = false;
        if (y + 1 < n && matrix[x][y + 1] < target)
            right = dfs(x, y + 1, target, matrix);
        return down || right;
    }
};
