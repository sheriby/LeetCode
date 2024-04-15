#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 1 2 3 4 5 6 =>  6 5 4 3 2 1 => 5 6 4 3 2 1 => 5 6 1 2 3 4
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            nums[i] = tmp[(i + len - k) % len];
        }
    }
};