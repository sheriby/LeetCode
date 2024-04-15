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
    // 利用了归并排序的思路
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }

   private:
    List mergeKListsHelper(vector<List>& lists, int left, int right) {
        if (left == right) return lists[left];
        if (left > right) return nullptr;
        int mid = left + ((right - left) >> 1);
        List l1 = mergeKListsHelper(lists, left, mid);
        List l2 = mergeKListsHelper(lists, mid + 1, right);
        return merge2Lists(l1, l2);
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        } else {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }
};