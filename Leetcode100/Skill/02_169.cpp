#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int len = nums.size();
        int target = len >> 1;

        for (int i = 0; i < len; i++) {
            if (++mp[nums[i]] > target) return nums[i];
        }
        return -1;
    }
};