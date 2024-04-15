#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;
        if (len < k) return res;
        priority_queue<PII> p;
        for (int i = 0; i < k; ++i) p.push({nums[i], i});
        res.push_back(p.top().first);

        for (int i = k; i < nums.size(); ++i) {
            p.push({nums[i], i});
            auto [val, idx] = p.top();
            while (idx < i - k + 1) {
                p.pop();
                val = p.top().first, idx = p.top().second;
            }
            res.push_back(val);
        }
        return res;
    }
};