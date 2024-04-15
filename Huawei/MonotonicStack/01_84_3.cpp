#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    // 2 1 5 6 2 3 利用单调栈，维护一个单调递增的序列，遇到小的就出栈
    // 还可以继续优化成一次遍历，入栈的时候确定左边界，出栈的时候确定右边界
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<int> st;
        vector<int> left(len);
        int res = 0;
        for (int i = 0; i < len; ++i) {
            while (st.size() && heights[i] <= heights[st.top()]) {
                // 出栈的时候知道右边界(不包含)
                int idx = st.top();
                res = max(res, heights[idx] * (i - left[idx] - 1));
                st.pop();
            }
            // 进栈的时候知道左边界(不包含)
            left[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        // 栈不为空，出栈
        while (st.size()) {
            int idx = st.top();
            res = max(res, heights[idx] * (len - left[idx] - 1));
            st.pop();
        }
        return res;
    }
};