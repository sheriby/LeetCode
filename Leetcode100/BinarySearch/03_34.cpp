#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] == target) {
                int l1 = m, r1 = m;
                while (l1 >= 0 && nums[l1] == target) l1--;
                while (r1 < len && nums[r1] == target) r1++;
                return {l1 + 1, r1 - 1};
            } else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return {-1, -1};
    }
};