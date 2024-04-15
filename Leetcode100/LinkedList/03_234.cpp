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
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next;
        while (slow) {
            stk.push(slow->val);
            slow = slow->next;
        }
        while (!stk.empty()) {
            if (head->val != stk.top()) return false;
            head = head->next;
            stk.pop();
        }
        return true;
    }

   private:
    stack<int> stk;
};