#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    // 单调栈找下一个更大的元素
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, -1);
        vector<bool> vis(len, false);
        int max_val = INT_MIN, max_cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] == max_val)
                max_cnt++;
            else if (nums[i] > max_val) {
                max_val = nums[i];
                max_cnt = 1;
            }
        }

        stack<int> st;
        int times = len - max_cnt;
        int i = 0;
        while (times) {
            while (st.size() && nums[st.top()] < nums[i]) {
                int idx = st.top();
                st.pop();
                if (!vis[idx]) {
                    times--;
                    res[idx] = nums[i];
                }
            }
            st.push(i);
            i = (i + 1) % len;
        }

        return res;
    }
};