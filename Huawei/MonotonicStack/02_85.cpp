#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    // 转化为84题，说实话有点bt了
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 存放每个点的左边有几个1(包括自己，自己也必须是1)
        vector<vector<int>> left(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1')
                    left[i][j] = (j == 0) ? 1 : left[i][j - 1] + 1;
            }
        }
        // 对每一列都用84题的方法
        int res = 0;
        for (int i = 0; i < n; ++i) {
            stack<int> st;
            vector<int> up(m, 0);

            // 单调栈的优化
            for (int j = 0; j < m; ++j) {
                while (st.size() && left[st.top()][i] >= left[j][i]) {
                    int idx = st.top();
                    // 找到右边界
                    res = max(res, left[idx][i] * (j - up[idx] - 1));
                    st.pop();
                }
                // 找到左边界
                up[j] = st.size() ? st.top() : -1;
                st.push(j);
            }

            while (st.size()) {
                int idx = st.top();
                res = max(res, left[idx][i] * (m - up[idx] - 1));
                st.pop();
            }
        }
        return res;
    }
};