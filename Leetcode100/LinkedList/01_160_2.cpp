#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> node_set;
        ListNode *p = headA;
        while (p) {
            node_set.insert(p);
            p = p->next;
        }
        p = headB;
        while (p) {
            if (node_set.count(p)) return p;
            p = p->next;
        }
        return nullptr;
    }
};