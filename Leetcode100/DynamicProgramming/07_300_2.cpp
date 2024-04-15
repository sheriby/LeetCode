#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 10,9,2,5,3,7,101,18
    // dp[i]: max length of i end with nums[i]
    // 10 => 9 => 2 => 2 5 => 2 3 => 2 3 7 => 2 3 7 101 => 2 3 7 18
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len + 1);
        int index = 1;
        dp[index] = nums[0];

        for (int i = 1; i < len; i++) {
            // greedy
            if (nums[i] > dp[index]) {
                dp[++index] = nums[i];
            } else {
                // binary search
                int left = 1, right = index;
                while (left <= right) {
                    int mid = left + ((right - left) >> 1);
                    if (dp[mid] < nums[i])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                dp[left] = nums[i];
            }
        }
        return index;
    }
};
