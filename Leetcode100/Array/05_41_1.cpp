#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i)
            if (nums[i] <= 0) nums[i] = len + 1;

        for (int i = 0; i < len; ++i) {
            int tmp = abs(nums[i]);
            if (tmp <= len) nums[tmp] = -abs(nums[tmp]);
        }

        for (int i = 0; i < len; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return len + 1;
    }
};