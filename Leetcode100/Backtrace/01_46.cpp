#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<int> visit(len, 0);
        vector<int> path;
        permute(nums, path, visit);
        return res;
    }

   private:
    vector<vector<int>> res;
    void permute(vector<int>& nums, vector<int>& path, vector<int>& visit) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visit[i] == 1) continue;
            visit[i] = 1;
            path.push_back(nums[i]);
            permute(nums, path, visit);
            path.pop_back();
            visit[i] = 0;
        }
    }
};