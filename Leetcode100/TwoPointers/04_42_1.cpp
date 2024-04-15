#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        int len = height.size();
        int rain_sum = 0;
        stack<int> st;
        for (int i = 0; i < len; ++i) {
            // 比栈顶的元素大
            while (!st.empty() && height[st.top()] <= height[i]) {
                int front = st.top();
                st.pop();
                // 计算front和i之间的雨水
                for (int k = front + 1; k < i; ++k) {
                    rain_sum += height[front] - height[k];
                    height[k] = height[front];
                }
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = len - 1; i >= 0; --i) {
            // 比栈顶的元素大
            while (!st.empty() && height[st.top()] <= height[i]) {
                int front = st.top();
                st.pop();
                // 计算front和i之间的雨水
                for (int k = i + 1; k < front; ++k) {
                    rain_sum += height[front] - height[k];
                    height[k] = height[front];
                }
            }
            st.push(i);
        }
        return rain_sum;
    }
};