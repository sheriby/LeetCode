#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int> &nums, int val) {
        int len = nums.size();
        int cot = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != val) {
                nums[cot++] = nums[i];
            }
        }
        return cot;
    }
};