#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 差分是前缀和的逆运算，diff[i] = num[i] - num[i-1], diff[0] = num[0]
    // 计算差分数组的前缀和就可以还原原数组
    // 差分数组在区间更新的问题上比较的有效，比如要将[l,r)区间中的所有的元素加上val
    // 只需要diff[l] += val,diff[r + 1] -=val 即可
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int len = trips.size();
        int max_to = -1;
        for (auto& trip : trips) max_to = max(max_to, trip[2]);

        vector<int> diff(max_to + 1, 0);

        // 差分在区间更新上比较的有效
        for (auto& trip : trips) {
            // 每次更新的是 [l, r)区间
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }
        // 还原原数组
        int cot = 0;
        for (int i = 0; i <= max_to; ++i) {
            cot += diff[i];
            if (cot > capacity) return false;
        }
        return true;
    }
};