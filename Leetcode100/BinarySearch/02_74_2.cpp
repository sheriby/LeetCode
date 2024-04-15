#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] > target) return false;
            int l = 0, r = n - 1;
            while (l <= r) {
                int m = l + ((r - l) >> 1);
                if (matrix[i][m] == target)
                    return true;
                else if (matrix[i][m] > target)
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
    }
};