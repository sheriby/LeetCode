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
    // 不做优化的话，倒数的几个样列会超时
    int rob(TreeNode *root) {
        if (!root) return 0;
        if (rmp.count(root)) return rmp[root];
        int res = max(root->val + norob(root->left) + norob(root->right),
                      norob(root));
        rmp[root] = res;
        return res;
    }

   private:
    unordered_map<TreeNode *, int> rmp;
    unordered_map<TreeNode *, int> nrmp;
    int norob(TreeNode *root) {
        if (!root) return 0;
        if (nrmp.count(root)) return nrmp[root];
        int res = rob(root->left) + rob(root->right);
        nrmp[root] = res;
        return res;
    }
};