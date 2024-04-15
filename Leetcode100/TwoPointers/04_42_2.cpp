#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 使用动态规划维护下标i处左右两边的最大的高度
    int trap(vector<int>& height) {
        int len = height.size();
        int rain_sum = 0;

        vector<int> left(len, 0);
        vector<int> right(len, 0);
        left[0] = height[0];
        right[len - 1] = height[len - 1];

        for (int i = 1; i < len; ++i) left[i] = max(left[i - 1], height[i]);
        for (int i = len - 2; i >= 0; --i)
            right[i] = max(right[i + 1], height[i]);

        for (int i = 0; i < len; ++i) {
            rain_sum += min(left[i], right[i]) - height[i];
        }

        return rain_sum;
    }
};