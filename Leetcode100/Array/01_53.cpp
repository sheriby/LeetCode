#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // -2,1,-3,4,-1,2,1,-5,4
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0], cur = nums[0];
        for (int i = 1; i < len; i++) {
            if (cur < 0 || cur + nums[i] <= 0) {
                cur = nums[i];
                res = max(res, cur);
            } else if (cur + nums[i] > 0) {
                cur += nums[i];
                res = max(res, cur);
            }
        }
        return res;
    }
};