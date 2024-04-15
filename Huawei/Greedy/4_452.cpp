#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    /*
       ---------
        ------
          ----
            ---------
    */
    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
        if (len == 1) return 1;
        // 将左端点从小到大排序
        sort(points.begin(), points.end());
        int right = points[0][1];
        int ans = 0;
        for (int i = 1; i < len; ++i) {
            int nleft = points[i][0], nright = points[i][1];
            // 两个区间不相干
            if (nleft > right) {
                ans++;
                right = nright;
            } else {
                right = min(right, nright);
            }
        }
        return ans;
    }
};