#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) >> 2;
                int val = matrix[i][mid];
                if (val == target)
                    return true;
                else if (val > target)
                    left = val + 1;
                else
                    right = val - 1;
            }
        }
    }
};
