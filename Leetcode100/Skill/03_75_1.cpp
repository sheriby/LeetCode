#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        vector<int> mp(3, 0);
        for (int i = 0; i < len; ++i) mp[nums[i]]++;
        for (int i = 0; i < len; ++i) {
            if (i < mp[0])
                nums[i] = 0;
            else if (i < mp[0] + mp[1])
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};