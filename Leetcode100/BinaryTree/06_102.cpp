#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> layers;
        if (!root) return layers;
        queue<Node> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> layer;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                Node front = q.front();
                q.pop();
                layer.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            layers.push_back(layer);
        }
        return layers;
    }
};