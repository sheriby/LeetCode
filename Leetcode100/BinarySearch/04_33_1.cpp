#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), k = 0;
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                k = i;
                break;
            }
        }
        int left = binarySearch(nums, 0, k, target);
        if (left != -1) return left;
        int right = binarySearch(nums, k + 1, len - 1, target);
        if (right != -1) return right;
        return -1;
    }

   private:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        int l = left, r = right;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) return mid;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
