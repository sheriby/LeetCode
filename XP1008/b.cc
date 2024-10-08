#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int find(vector<int> &arr) {
        vector<int> path;
        set<vector<int>> _set;
        dfs(0, path, arr, _set);
        return _set.size();
    }

  private:
    void dfs(int index, vector<int> &path, vector<int> &arr,
             set<vector<int>> &_set) {
        if (path.size() >= 2) {
            _set.insert(path);
        }

        for (int i = index; i < arr.size(); i++) {
            if (path.empty() || arr[i] >= path.back()) {
                path.push_back(arr[i]);
                dfs(i + 1, path, arr, _set);
                path.pop_back();
            }
        }
    }
};
