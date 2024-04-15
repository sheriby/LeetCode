#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int f[10000];

int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}

void _union(int x, int y) { f[find(x)] = find(y); }

class Solution {
   public:
    // 也可以用并查集做
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    f[i * n + j + 1] = i * n + j + 1;
                    if (i - 1 >= 0 && grid[i - 1][j] == '1')
                        _union(i * n + j + 1, (i - 1) * n + j + 1);
                    if (j - 1 >= 0 && grid[i][j - 1] == '1')
                        _union(i * n + j + 1, (i)*n + j);
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= m * n; ++i) {
            if (f[i] == i) res++;
        }

        return res;
    }
};

int main() {
    vector<vector<char>> grid = {{'0'}};
    Solution s;
    cout << s.numIslands(grid) << endl;
    return 0;
}