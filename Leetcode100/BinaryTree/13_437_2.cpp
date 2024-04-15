#include <algorithm>
#include <iostream>
#include <unordered_map>
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
        prefixs[0] = 1;
        return dfs(root, 0, targetSum);
    }

   private:
    unordered_map<long long, int> prefixs;
    int dfs(Node root, long long cur, int targetSum) {
        if (!root) return 0;

        cur += root->val;
        int res = prefixs[cur - targetSum];
        prefixs[cur]++;
        res += dfs(root->left, cur, targetSum);
        res += dfs(root->right, cur, targetSum);
        prefixs[cur]--;
        return res;
    }
};