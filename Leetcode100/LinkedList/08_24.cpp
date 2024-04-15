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

typedef ListNode* List;
class Solution {
   public:
    // 1->2->3->4
    // 2->1->4->3
    ListNode* swapPairs(ListNode* head) {
        ListNode *nhead = new ListNode(0), *p = nhead;
        nhead->next = head;
        while (p->next && p->next->next) {
            ListNode *node1 = p->next, *node2 = p->next->next;
            p->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            p = node1;
        }
        ListNode* tmp = nhead->next;
        delete nhead;
        return tmp;
    }
};