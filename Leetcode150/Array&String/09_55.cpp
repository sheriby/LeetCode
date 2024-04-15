#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int last_ture = len - 1;
        for (int i = len - 2; i >= 0; i--)
            if (i + nums[i] >= last_ture) last_ture = i;
        return last_ture == 0;
    }
};