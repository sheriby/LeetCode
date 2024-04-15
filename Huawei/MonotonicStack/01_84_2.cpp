#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    // 2 1 5 6 2 3 利用单调栈，维护一个单调递增的序列，遇到小的就出栈
    // 这种方法会TLE，使用left和right数组进行优化
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<int> st;
        // left和right维护的索引都是不包含的 (left, right)
        vector<int> left(len), right(len);
        // 从左到右
        for (int i = 0; i < len; ++i) {
            // 栈顶的元素比当前的元素大或者相等，出栈
            while (st.size() && heights[i] <= heights[st.top()]) st.pop();
            left[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        st = stack<int>();
        // 从右到左
        for (int i = len - 1; i >= 0; --i) {
            while (st.size() && heights[i] <= heights[st.top()]) st.pop();
            right[i] = st.size() ? st.top() : len;
            st.push(i);
        }
        int res = 0;
        for (int i = 0; i < len; ++i) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};