#include <algorithm>
#include <iostream>
#include <stack>
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

typedef TreeNode* Tree;
typedef TreeNode* Node;

class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        Node left = root->left, right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};