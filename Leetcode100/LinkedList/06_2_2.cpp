#include <algorithm>
#include <iostream>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2, *head = nullptr, *t = nullptr;
        int jw = 0;
        while (p || q) {
            int pval = 0, qval = 0;
            if (p) {
                pval = p->val;
                p = p->next;
            }
            if (q) {
                qval = q->val;
                q = q->next;
            }
            int sum = pval + qval + jw;
            jw = sum / 10;
            if (t) {
                t->next = new ListNode(sum % 10);
                t = t->next;
            } else {
                t = new ListNode(sum % 10);
                head = t;
            }
        }
        if (jw) {
            t->next = new ListNode(jw);
        }
        return head;
    }
};