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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        return BSTHelper(nums, 0, len);
    }

   private:
    TreeNode* BSTHelper(vector<int>& nums, int start, int end) {
        if (start >= end) return nullptr;
        int mid = start + ((end - start) >> 2);
        Node head = new TreeNode(nums[mid]);
        head->left = BSTHelper(nums, start, mid);
        head->right = BSTHelper(nums, mid + 1, end);
        return head;
    }
};
