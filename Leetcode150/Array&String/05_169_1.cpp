#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < len; i++) {
            map[nums[i]]++;
        }
        int half = len * 1.0 / 2;
        for (auto it : map) {
            if (it.second > half) return it.first;
        }
        return 0;
    }
};