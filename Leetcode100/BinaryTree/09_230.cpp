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
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        midOrder(root);
        return this->ans;
    }

   private:
    int cot = 0;
    int ans = 0;
    int k = 0;
    void midOrder(TreeNode* root) {
        if (!root) return;
        if (root->left) midOrder(root->left);
        if (++cot == k) {
            ans = root->val;
            return;
        }
        if (root->right) midOrder(root->right);
    }
};