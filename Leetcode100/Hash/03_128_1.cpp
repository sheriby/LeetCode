#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxl = 0, len = nums.size();
        int i, j, same;
        for (i = 0; i < len; i++) {
            same = 0;
            for (j = i + 1; j < len; j++) {
                if (nums[j] == nums[j - 1]) {
                    same += 1;
                } else if (nums[j] != nums[j - 1] + 1)
                    break;
            }
            if (j - i - same > maxl) maxl = j - i - same;
            i = j - 1;
        }
        return maxl;
    }
};