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
    // a -> b -> c -> d -> e
    // a -> b <- c <- d <- e
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* rHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rHead;
    }
};