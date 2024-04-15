#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    // 单调栈+循环数组
    // 1 2 3 4 3 => 1 2 3 4 3 1 2 3 4  // 长度变成了2*len - 1
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, -1);
        stack<int> stk;

        for (int i = 0; i < 2 * len - 1; ++i) {
            while (stk.size() && nums[stk.top()] < nums[i % len]) {
                res[stk.top()] = nums[i % len];
                stk.pop();
            }
            stk.push(i % len);
        }

        return res;
    }
};