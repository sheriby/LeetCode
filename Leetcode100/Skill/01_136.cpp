#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 0 ^ 0 = 0, 1 ^ 0 = 0, 0 ^ 1 = 1, 1 ^ 1 =
    // 0，也就是说1、异或0不变，异或1相反。2、自己异或变0 A ^ A = 0, A ^ 0 = A
    // a ^ b ^ a ^ c ^ b = (a ^ a) ^ (b ^ b) ^ c = 0 ^ 0 ^ c = c
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) res ^= nums[i];
        return res;
    }
};