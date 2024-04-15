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
    // 3 9 20 15 7
    // 9 3 15 20 7 ==> head is 3, left tree: 3, right tree: 15 20 78
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return buildTreeHelper(preorder, inorder, 0, len - 1, 0, len - 1);
    }

   private:
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                              int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) return nullptr;
        int h = preorder[ps];

        Node head = new TreeNode(h);
        if (ps == pe) return head;
        int inhead = 0;

        for (int i = is; i <= ie; i++) {
            if (inorder[i] == h) {
                inhead = i;
                break;
            }
        }

        int lNum = inhead - is, rNum = ie - inhead;
        head->left = buildTreeHelper(preorder, inorder, ps + 1, ps + lNum, is,
                                     inhead - 1);
        head->right = buildTreeHelper(preorder, inorder, ps + lNum + 1, pe,
                                      inhead + 1, ie);
        return head;
    }
};