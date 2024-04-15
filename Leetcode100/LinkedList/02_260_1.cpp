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
    // a <- b <- c <- d <- e
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *cur = head, *next = head->next, *prev = nullptr;
        while (cur) {
            cur->next = prev;
            prev = cur;
            if (!next) return cur;
            cur = next;
            next = next->next;
        }
    }
};