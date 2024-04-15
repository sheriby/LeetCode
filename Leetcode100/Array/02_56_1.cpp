#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // [[1,3],[2,6],[8,10],[15,18]]
    // => [1,6], [8,10], [15.18]
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(),
             [](auto a, auto b) { return a[0] < b[0]; });

        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < len; i++) {
            if (intervals[i][0] >= right)
                right = max(right, intervals[i][1]);
            else {
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};