#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len + 1, 0);
        int sum = 0;
        for (int i = 1; i <= len; ++i) {
            sum += nums[i - 1];
            prefix[i] = sum;
        }
        for (int i = 0; i < len; ++i)
            if (2 * prefix[i] == sum - nums[i]) return i;

        return -1;
    }
};