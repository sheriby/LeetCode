#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int left = 0, sum = 0, min_len = INT_MAX;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            if (sum >= target) {
                while (left <= i && sum >= target) {
                    sum -= nums[left++];
                }
                // [left - 1, i] // 为窗口
                min_len = min(min_len, i - left + 2);
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};