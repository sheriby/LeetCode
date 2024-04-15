#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum = 0, max_sum = nums[0];
        for (int i = 0; i < len; ++i) {
            sum = max(sum + nums[i], nums[i]);
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};