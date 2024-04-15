#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA), lenB = getLen(headB);
        if (lenA > lenB)
            for (int i = 0; i < lenA - lenB; i++) headA = headA->next;
        if (lenA < lenB)
            for (int i = 0; i < lenB - lenA; i++) headB = headB->next;

        while (headA) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

   private:
    int getLen(ListNode *head) {
        int n = 0;
        while (head) {
            head = head->next;
            n++;
        }
        return n;
    }
};