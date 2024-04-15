#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<int> path;
        dfs(nums, path, 0);
        return res;
    }

   private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& path, int cur) {
        if (cur == nums.size()) {
            res.push_back(path);
            return;
        }
        path.push_back(nums[cur]);
        dfs(nums, path, cur + 1);
        path.pop_back();
        dfs(nums, path, cur + 1);
    }
};