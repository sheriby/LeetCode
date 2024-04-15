#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int first = 0, second = 0, res = 0;
        for (int i = 0; i < len; i++) {
            res = max(second, first + nums[i]);
            first = second;
            second = res;
        }
        return res;
    }
};