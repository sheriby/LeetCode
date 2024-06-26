#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val < list2->val) {
            ListNode* nhead = mergeTwoLists(list1->next, list2);
            list1->next = nhead;
            return list1;
        } else {
            ListNode* nhead = mergeTwoLists(list1, list2->next);
            list2->next = nhead;
            return list2;
        }
    }
};