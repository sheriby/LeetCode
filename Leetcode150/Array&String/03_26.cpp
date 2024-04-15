#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int p = 0, q = 1;
        while (q < len) {
            while (q < len && nums[p] == nums[q]) q++;
            if (q < len) nums[++p] = nums[q++];
        }
        return p + 1;
    }
};