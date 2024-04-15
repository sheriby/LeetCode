#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> res(len, 0);
        if (!len) return res;
        stack<pair<int, int>> st;
        st.push({temperatures[0], 0});
        for (int i = 0; i < len; i++) {
            while (!st.empty() && st.top().first < temperatures[i]) {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};