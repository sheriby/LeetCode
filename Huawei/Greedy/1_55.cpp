#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int max_dis = 0;
        for (int i = 0; i < len; ++i) {
            if (i > max_dis) return false;
            max_dis = max(max_dis, i + nums[i]);
            if (max_dis >= len) return true;
        }
        return true;
    }
};