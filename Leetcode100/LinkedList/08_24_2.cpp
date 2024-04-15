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
        if (!head || !head->next) return head;
        ListNode *node1 = head, *node2 = head->next;
        ListNode* rhead = swapPairs(node2->next);
        node2->next = node1;
        node1->next = rhead;
        return node1;
    }
};