#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        long long mul = 1;
        int zero_count = 0;
        int zero_index = -1;
        for (int i = 0; i < len; i++) {
            if (!nums[i])
                mul *= nums[i];
            else {
                zero_count++;
                zero_index = i;
            }
        }
        if (zero_count > 1) {
            fill(nums.begin(), nums.end(), 0);
        } else if (zero_count == 1) {
            fill(nums.begin(), nums.end(), 0);
            nums[zero_index] = mul;
        } else {
            for (int i = 0; i < len; i++) nums[i] = mul / nums[i];
        }
        return nums;
    }
};