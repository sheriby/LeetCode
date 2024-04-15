#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 0 1 0 0 3 12 => 1 0 0 0 3 12
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return;
        int p = 0, q = 0;
        while (nums[p]) p++;
        q = p + 1;
        while (q < len) {
            if (nums[q]) swap(nums[p++], nums[q]);
            q++;
        }
    }
};