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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return pathSumWithRoot(root, targetSum) +
               pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

   private:
    int pathSumWithRoot(Node root, long long targetSum) {
        int cot = 0;
        if (root->val == targetSum) cot++;
        if (root->left)
            cot += pathSumWithRoot(root->left, targetSum - root->val);
        if (root->right)
            cot += pathSumWithRoot(root->right, targetSum - root->val);
        return cot;
    }
};