#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    // 计算每个位置前面的奇数的数量
    // odd[i, j] = odd[0, j] - odd[0, i]
    int numberOfSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cot = 0, res = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] & 1) cot++;
            res += mp[cot - k];
            mp[cot]++;
        }
        return res;
    }
};