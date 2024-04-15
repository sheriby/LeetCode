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

typedef TreeNode* Tree;
typedef TreeNode* Node;
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        midOrder(root, res);
        return res;
    }

   private:
    void midOrder(Tree root, vector<int>& res) {
        if (!root) return;
        if (root->left) midOrder(root->left, res);
        res.push_back(root->val);
        if (root->right) midOrder(root->right, res);
    }
};