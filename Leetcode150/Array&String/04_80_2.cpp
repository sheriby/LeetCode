#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;

        int slow = 2, fast = 2;
        while (fast < len) {
            if (nums[slow - 2] != nums[fast]) nums[slow++] = nums[fast];
            fast++;
        }
        return slow;
    }
};