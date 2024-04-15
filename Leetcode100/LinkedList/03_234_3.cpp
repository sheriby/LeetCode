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
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {  // 确保fast还有两格可以跳
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *rhead = reverseList(slow->next);
        while (rhead && head) {
            if (head->val != rhead->val) return false;
            head = head->next;
            rhead = rhead->next;
        }
        return true;
    }

   private:
    ListNode *reverseList(ListNode *head) {
        if (!head) return head;
        ListNode *cur = head, *next = head->next, *prev = nullptr;
        while (cur) {
            cur->next = prev;
            prev = cur;
            if (!next) return cur;
            cur = next;
            next = next->next;
        }
    }
};