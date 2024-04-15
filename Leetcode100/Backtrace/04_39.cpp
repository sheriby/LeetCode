#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, path, 0, 0, target);
        return res;
    }

   private:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, vector<int>& path, int sum, int index,
             int target) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(path);
            return;
        }
        int len = candidates.size();
        for (int i = 0; i < len; i++) {
            if (i < index) continue;
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, path, sum, i, target);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};