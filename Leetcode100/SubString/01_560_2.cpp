#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    // -1 1 2 1 -1   2
    // -1 0 2 3 2
    // g[i][j] = f[j] - f[i]
    // f[j] - f[i] = k => f[i] = f[j] - k
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int cot = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            cot += map[sum - k];
            map[sum]++;
        }
        return cot;
    }
};