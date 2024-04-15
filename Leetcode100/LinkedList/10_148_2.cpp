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
    ListNode *sortList(ListNode *head) { return sortList(head, nullptr); }

   private:
    ListNode *sortList(List head, List end) {
        if (!head) return head;
        if (head->next == end) {
            head->next = nullptr;
            return head;
        }
        List slow = head, fast = head;
        while (fast && fast != end) {
            slow = slow->next;
            fast = fast->next;
            if (fast != end) fast = fast->next;
        }
        List mid = slow;
        List left = sortList(head, mid);
        List right = sortList(mid, end);
        return merge(left, right);
    }

    List merge(List left, List right) {
        List head = new ListNode(0);
        List h = head, p = left, q = right;
        while (p && q) {
            if (p->val < q->val) {
                h->next = p;
                p = p->next;
            } else {
                h->next = q;
                q = q->next;
            }
        }
        if (p)
            h->next = p;
        else if (q)
            h->next = q;
        else
            h->next = nullptr;

        return head->next;
    }
};