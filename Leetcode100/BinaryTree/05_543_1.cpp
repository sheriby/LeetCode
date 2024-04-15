#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

typedef TreeNode* Node;

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameterHelper(root);
    }

   private:
    int diameterHelper(Node root) {
        if (!root) return 0;
        int leftDepth = 0, rightDepth = 0;
        if (root->left) leftDepth = root->left->val;
        if (root->right) rightDepth = root->right->val;
        return max(leftDepth + rightDepth, max(diameterHelper(root->left),
                                               diameterHelper(root->right)));
    }
    int depth(Node node) {
        if (!node) return 0;
        int d = 1 + max(depth(node->left), depth(node->right));
        node->val = d;
        return d;
    }
};