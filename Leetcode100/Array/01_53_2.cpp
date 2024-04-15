#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum = 0, min_sum = 0, max_sum = nums[0];
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            max_sum = max(max_sum, sum - min_sum);
            min_sum = min(sum, min_sum);
        }
        return max_sum;
    }
};