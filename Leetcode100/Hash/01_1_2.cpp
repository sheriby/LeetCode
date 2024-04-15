#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) return {i, it->second};
            map[nums[i]] = i;
        }
        return {};
    }
};