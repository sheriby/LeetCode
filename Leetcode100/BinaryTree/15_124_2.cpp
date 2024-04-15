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
    int maxPathSum(TreeNode *root) {
        dfs(root);
        return max_path;
    }

   private:
    int max_path = 0;
    int dfs(Node root) {
        if (!root) return 0;
        int res = root->val;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        // 以当前的结点为根
        max_path = max(max_path, root->val + left + right);
        return root->val + max(left, right);
    }
};