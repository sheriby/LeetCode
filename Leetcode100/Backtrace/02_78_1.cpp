#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<int> path;
        subset(nums, path, 0);
        return res;
    }

   private:
    vector<vector<int>> res;
    void subset(vector<int>& nums, vector<int>& path, int index) {
        res.push_back(path);
        for (int i = 0; i < nums.size(); i++) {
            if (i < index) continue;
            path.push_back(nums[i]);
            subset(nums, path, i + 1);
            path.pop_back();
        }
    }
};