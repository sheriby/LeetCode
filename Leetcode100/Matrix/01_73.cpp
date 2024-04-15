#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int hasZeroM[201] = {0}, hasZeroN[201] = {0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    hasZeroM[i] = 1;
                    hasZeroN[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (hasZeroM[i] || hasZeroN[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};