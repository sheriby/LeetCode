#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return nums[i + 1];
            }
        }
        return nums[0];
    }
};