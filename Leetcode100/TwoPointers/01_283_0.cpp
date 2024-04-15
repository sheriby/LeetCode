#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        vector<int> copy(nums);
        int idx = 0;
        for (int i = 0; i < len; ++i)
            if (copy[i]) nums[idx++] = copy[i];
        while (idx < len) nums[idx++] = 0;
    }
};