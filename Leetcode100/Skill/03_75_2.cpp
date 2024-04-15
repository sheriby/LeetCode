#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1++]);
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) swap(nums[i], nums[p1++]);
            }
        }
    }
};