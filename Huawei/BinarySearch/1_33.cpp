#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 4 5 6 7 0 1 2
    // 每次二分的时候两边必有一个有序的数组
    // 4 5 6  7  0 1 2  左面有序
    // 5 1 3
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) return mid;
            // 左面是有序的 [l, mid]
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;  // 在这个有序区间
                else
                    l = mid + 1;
            }
            // 右面是有序的
            if (nums[mid] <= nums[r]) {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;  // 在这个有序区间
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};