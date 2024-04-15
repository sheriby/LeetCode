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
            while (!st.empty() && height[st.top()] < height[i]) {
                int front = st.top();
                st.pop();
                if (st.empty()) break;
                int left = st.top();
                int w = i - left - 1;
                int h = min(height[left], height[i]) - height[front];
                rain_sum += w * h;
            }
            st.push(i);
        }
        return rain_sum;
    }
};