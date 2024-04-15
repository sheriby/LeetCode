#include <algorithm>
#include <iostream>
#include <unordered_map>
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
    // 利用节点的前缀和，节点的前缀和指的是从根节点到该节点的路径上的所有节点值的和
    // 需要使用先序的遍历
    int pathSum(TreeNode *root, int targetSum) {
        mp[0] = 1;
        return dfs(root, 0, targetSum);
    }

   private:
    unordered_map<ll, int> mp;
    int dfs(TreeNode *root, ll cur, int target) {
        if (!root) return 0;
        cur += root->val;  // cur为该节点的前缀和
        int res = mp[cur - target];

        mp[cur]++;  // 访问该节点后面的结点，需要保存先序
        if (root->left) res += dfs(root->left, cur, target);
        if (root->right) res += dfs(root->right, cur, target);
        mp[cur]--;  // 离开该节点后面的结点，去除前缀和

        return res;
    }
};