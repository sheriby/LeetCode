#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int idx = 0;
        int cot = 1;
        for (int i = 1; i < len; i++) {
            if (nums[i] != nums[idx]) {
                if (cot >= 2) {
                    nums[idx + 1] = nums[idx];
                    cot = 2;
                }
                idx += cot;
                nums[idx] = nums[i];
                cot = 1;
            } else
                cot++;
        }
        if (cot >= 2) {
            nums[idx + 1] = nums[idx];
            idx++;
        }
        return idx + 1;
    }
};

int main(int argc, char const* argv[]) {
    Solution s = Solution();
    vector<int> nums = {1, 1, 1, 1, 2, 2, 3};
    int res = s.removeDuplicates(nums);
    for (int i = 0; i < res; i++) {
        cout << nums[i] << ", ";
    }
    cout << endl;
    return 0;
}
