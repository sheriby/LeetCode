#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // sum[i, j]= sum[0, j] - sum [0, i-1]
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> prefix(len, 0);
        int res = 0, sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            prefix[i] = sum;
            if (sum == k) ++res;
            for (int j = 0; j < i; ++j)
                if (prefix[j] == sum - k) ++res;
        }

        return res;
    }
};