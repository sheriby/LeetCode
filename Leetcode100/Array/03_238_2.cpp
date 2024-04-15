#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> suffix(len);
        vector<int> res(len);

        int sfix = 1, pfix = 1;
        for (int i = len - 1; i >= 0; --i) {
            suffix[i] = sfix;
            sfix *= nums[i];
        }
        for (int i = 0; i < len; ++i) {
            res[i] = pfix * suffix[i];
            pfix *= nums[i];
        }
        return res;
    }
};