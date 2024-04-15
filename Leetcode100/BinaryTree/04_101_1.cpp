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

typedef TreeNode* Tree;
typedef TreeNode* Node;

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        Node left = root, right = root;
        queue<Node> lq, rq;
        lq.push(root->left);
        rq.push(root->right);

        while (!lq.empty() && !rq.empty()) {
            if (lq.size() != rq.size()) return false;
            left = lq.front(), right = rq.front();
            lq.pop();
            rq.pop();
            if (!left && !right) continue;
            if ((!left && right) || (left && !right)) return false;
            if (left->val != right->val) return false;
            lq.push(left->left);
            lq.push(left->right);
            rq.push(right->right);
            rq.push(right->left);
        }
        return true;
    }
};