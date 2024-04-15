#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] != nums[r]) return false;
            ++l, --r;
        }

        return true;
    }
};