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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *p = head, *q = head;
        while (p) ++len, p = p->next;
        if (n > len) return head;
        if (n == len) return head->next;
        for (int i = 0; i < len - n - 1; ++i) q = q->next;
        q->next = q->next->next;
        return head;
    }
};