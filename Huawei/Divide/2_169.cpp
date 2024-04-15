#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 利用分治法计算出众数
    // 将数组一分为二变成两块，如果存在众数的话，那边其必然是两边至少一边的众数
    int majorityElement(vector<int>& nums) {
        return majorithElementHelper(nums, 0, nums.size() - 1);
    }

   private:
    bool isMajority(vector<int>& nums, int left, int right, int target) {
        int cnt = 0;
        for (int i = left; i <= right; ++i) {
            if (nums[i] == target) cnt++;
        }
        if (cnt > (right - left + 1) >> 1) return true;
        return false;
    }

    int majorithElementHelper(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int leftMajor = majorithElementHelper(nums, left, mid);
        int rightMajor = majorithElementHelper(nums, mid + 1, right);
        if (isMajority(nums, left, right, leftMajor)) return leftMajor;
        if (isMajority(nums, left, right, rightMajor)) return rightMajor;
        return -1;
    }
};