#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

typedef TreeNode *Node;
typedef long long ll;
class Solution {
   public:
    int pathSum(TreeNode *root, int targetSum) {
        return pathSumWith(root, targetSum) + pathSumWithout(root, targetSum);
    }

   private:
    // 转化为路径是否经过该节点的问题
    int pathSumWith(TreeNode *root, ll target) {
        if (!root) return 0;
        int res = 0;
        if (root->val == target) ++res;
        res += pathSumWith(root->left, target - root->val) +
               pathSumWith(root->right, target - root->val);
        return res;
    }
    int pathSumWithout(TreeNode *root, ll target) {
        if (!root) return 0;
        return pathSum(root->left, target) + pathSum(root->right, target);
    }
};