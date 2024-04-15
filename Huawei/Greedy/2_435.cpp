#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (!len) return 0;
        // 将所有的区间按照右端点进行排序
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        int ans = 0;
        int right = intervals[0][1];
        for (int i = 1; i < len; ++i) {
            // 左端点大于右端点，说明这是一个合理的区间，不用删除
            if (intervals[i][0] >= right) {
                ans++;
                // 更新右端点
                right = intervals[i][1];
            }
        }
        return len - ans;
    }
};