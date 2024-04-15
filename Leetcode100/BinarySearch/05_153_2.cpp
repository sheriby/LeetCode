#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (m - 1 > 0 && nums[m] < nums[m - 1]) {
                return nums[m];
            }
            if (m + 1 < len && nums[m] > nums[m + 1]) {
                return nums[m + 1];
            }
            if (nums[l] <= nums[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return nums[0];
    }
};