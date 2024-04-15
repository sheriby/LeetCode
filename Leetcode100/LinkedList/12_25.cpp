#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode* p = head;
        for (int i = 0; i < k - 1; ++i) {
            p = p->next;
            if (!p) return head;
        }
        ListNode* q = p->next;
        p->next = nullptr;
        ListNode* lhead = reverse(head);
        head->next = reverseKGroup(q, k);
        return lhead;
    }

   private:
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* rhead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rhead;
    }
};