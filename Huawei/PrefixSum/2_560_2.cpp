#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    // sum[i, j]= sum[0, j] - sum [0, i-1]
    // 使用hashmap优化
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};