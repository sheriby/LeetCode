#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
class Solution {
   public:
    // 2 1 5 6 2 3 利用单调栈，维护一个单调递增的序列，遇到小的就出栈
    // 这种方法会TLE，使用left和right数组进行优化
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        int res = heights[0];
        vector<PII> st;
        st.push_back({heights[0], 0});
        for (int i = 1; i < len; ++i) {
            int tval = st.back().first;
            if (heights[i] >= tval) {
                st.push_back({heights[i], i});
                for (int k = 0; k < st.size(); ++k)
                    res = max(res, st[k].first * (i - st[k].second + 1));

            } else {
                int idx = 0;
                while (st.size() && heights[i] < st.back().first) {
                    idx = st.back().second;
                    st.pop_back();
                }
                st.push_back({heights[i], idx});
                for (int k = 0; k < st.size(); ++k)
                    res = max(res, st[k].first * (i - st[k].second + 1));
            }
        }
        return res;
    }
};