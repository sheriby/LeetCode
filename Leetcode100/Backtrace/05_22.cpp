#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }

   private:
    vector<string> res;
    void dfs(int n, int left, int right, string path) {
        if (left == n && right == n) {
            res.push_back(path);
            return;
        }
        if (left < n) dfs(n, left + 1, right, path + '(');
        if (right < left) dfs(n, left, right + 1, path + ')');
    }
};