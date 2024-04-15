#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 用二分法找到有序数组当中的第一个元素
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1, first = -1, last = -1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) {
                first = mid;
                r = mid - 1;  // 继续向左面寻找
            } else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (first != -1) {
            for (int i = first + 1; i < len; ++i) {
                if (nums[i] == target) last = i;
            }
        }
        return {first, last};
    }
};