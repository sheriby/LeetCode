#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int max = 0, cur = 0;
        int left = 0, right = len - 1;
        while (left < right) {
            cur = (right - left) * min(height[right], height[left]);
            if (cur > max) max = cur;
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max;
    }
};