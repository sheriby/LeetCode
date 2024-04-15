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
        int res = maxPathSumWith(root);
        if (root->left) res = max(res, maxPathSum(root->left));
        if (root->right) res = max(res, maxPathSum(root->right));
        return res;
    }

   private:
    int maxPathSumWith(Node root) {
        int res = root->val;
        if (root->left) res += max(0, maxPathSumWithOne(root->left));
        if (root->right) res += max(0, maxPathSumWithOne(root->right));
        return res;
    }

    int maxPathSumWithOne(Node root) {
        int res = root->val;
        if (!root->left && !root->right) return res;
        if (root->left && root->right)
            return res + max(0, max(maxPathSumWithOne(root->left),
                                    maxPathSumWithOne(root->right)));
        if (root->left) return res + max(0, maxPathSumWithOne(root->left));
        return res + max(0, maxPathSumWithOne(root->right));
    }
};