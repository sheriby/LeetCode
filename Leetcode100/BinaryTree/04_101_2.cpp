#include <algorithm>
#include <iostream>
#include <queue>
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
    bool isSymmetric(TreeNode* root) { return check(root, root); }

   private:
    bool check(Node left, Node right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val && check(left->right, right->left) &&
               check(left->left, right->right);
    }
};