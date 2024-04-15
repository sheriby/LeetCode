#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        int res = 0, left = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] == 1) {
                res = max(res, i - left + 1);
            } else if (k) {
                res = max(res, i - left + 1);
                k--;
            } else {
                for (int j = left; j <= i; ++j) {
                    if (nums[j] == 0) {
                        left = j + 1;
                        break;
                    }
                }
                res = max(res, i - left + 1);
            }
        }
        return res;
    }
};
