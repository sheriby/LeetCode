#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 只有一个数出现了多次，其他数都只出现了一次
    // 1 2 3 4 2
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int res;
        int l = 0, r = len - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1), cnt = 0;
            for (int i = 0; i < len; ++i) {
                if (nums[i] <= mid) cnt++;
            }
            if (cnt > mid) {
                res = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return res;
    }
};