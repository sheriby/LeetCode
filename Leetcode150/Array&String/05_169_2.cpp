#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int count = 0, candicate = -1;

        for (int i = 0; i < len; i++) {
            if (nums[i] == candicate)
                count++;
            else if (--count < 0) {
                candicate = nums[i];
                count = 1;
            }
        }
        return candicate;
    }
};