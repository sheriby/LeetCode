#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();

        vector<pair<int, int>> pairs;
        for (int i = 0; i < len; i++) {
            pairs.push_back(make_pair(nums[i], i));
        }

        sort(pairs.begin(), pairs.end(),
             [](auto a, auto b) { return a.first > b.first });

        int p = 0, q = len - 1;
        while (p < q) {
            int tmp = pairs[p].first + pairs[q].first;
            if (tmp == target)
                return {pairs[p].second, pairs[q].second};
            else if (tmp > target)
                q--;
            else
                p++;
        }
        return nums;
    }
};