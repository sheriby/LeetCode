#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> node_set;
        while (head) {
            if (node_set.count(head)) return true;
            node_set.insert(head);
            head = head->next;
        }
        return false;
    }
};