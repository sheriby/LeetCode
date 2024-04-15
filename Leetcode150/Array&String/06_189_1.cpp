#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 1 2 3 4 5 6 =>  5 6 1 2 3 4
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        int start = len - k;
        vector<int> tmp(len, 0);
        for (int i = 0; i < len; i++) {
            int idx = (start + i) % len;
            tmp[i] = nums[idx];
        }
        for (int i = 0; i < len; i++) {
            nums[i] = tmp[i];
        }
    }
};