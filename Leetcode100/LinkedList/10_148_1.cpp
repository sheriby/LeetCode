#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode *List;
class Solution {
   public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        List p = head, q = nullptr, e = nullptr, prev = nullptr;
        while (p && p->next != e) {
            q = p->next;
            while (q != e) {
                if (p->val > q->val) swap(q->val, p->val);
                p = p->next;
                prev = q;
                q = q->next;
            }
            e = prev;
            p = head;
        }
        return head;
    }
};