#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        unordered_set<int> set;
        for (auto num : nums) {
            set.insert(num);
        }
        int cur = 1, max = 1;
        for (auto it = set.begin(); it != set.end(); it++) {
            if (set.count(*it - 1)) continue;

            cur = 1;
            int next = *it + 1;
            while (set.count(next)) {
                cur++;
                next += 1;
            }
            if (cur > max) max = cur;
        }
        return max;
    }
};