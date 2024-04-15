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
    void flatten(TreeNode* root) { root = flattenHelper(root); }

   private:
    Node flattenHelper(Node root) {
        if (!root) return root;
        Node lt = flattenHelper(root->left);
        Node rt = flattenHelper(root->right);
        root->right = lt;
        Node p = root;
        while (p->right) {
            p->left = nullptr;
            p = p->right;
        }
        p->left = nullptr;
        p->right = rt;
        return root;
    }
};
