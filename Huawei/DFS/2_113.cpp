#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

typedef TreeNode *Node;
class Solution {
   public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return res;
    }

   private:
    vector<vector<int>> res;
    void dfs(Node root, int target, vector<int> path) {
        if (!root) return;
        if (!root->left && !root->right && root->val == target) {
            path.push_back(root->val);
            res.push_back(path);
            return;
        }
        path.push_back(root->val);
        dfs(root->left, target - root->val, path);
        dfs(root->right, target - root->val, path);
        path.pop_back();
    }
};