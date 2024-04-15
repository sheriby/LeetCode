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
        return ans;
    }

   private:
    int depth(Node node) {
        if (!node) return 0;
        int ld = depth(node->left);
        int rd = depth(node->right);
        ans = max(ans, ld + rd);
        return max(ld, rd) + 1;
    }
    int ans = 0;
};