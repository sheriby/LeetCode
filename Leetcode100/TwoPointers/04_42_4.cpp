#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        int len = height.size();
        int rain_sum = 0;
        int left = 0, right = 0;
        int l = 0, r = len - 1;
        while (l < r) {
            left = max(left, height[l]);
            right = max(right, height[r]);
            if (height[l] < height[r]) {
                rain_sum += left - height[l];
                l++;
            } else {
                rain_sum += right - height[r];
                r--;
            }
        }
        return rain_sum;
    }
};