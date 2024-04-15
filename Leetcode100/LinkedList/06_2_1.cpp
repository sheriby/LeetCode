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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1[105] = {0}, n2[105] = {0}, n3[105] = {0};
        int s1 = List2Arr(l1, n1), s2 = List2Arr(l2, n2);
        int maxs = max(s1, s2);
        int jw = 0;
        for (int i = 0; i < maxs; i++) {
            int sum = n1[i] + n2[i] + jw;
            jw = sum / 10;
            n3[i] = sum % 10;
        }
        int len = 0;
        if (jw) {
            n3[maxs] = jw;
            len = maxs;
        } else
            len = maxs - 1;
        return Arr2List(n3, len);
    }

   private:
    int List2Arr(ListNode* head, int arr[]) {
        int cot = 0;
        while (head) {
            arr[cot++] = head->val;
            head = head->next;
        }
        return cot;
    }
    ListNode* Arr2List(int arr[], int len) {
        ListNode* head = new ListNode(arr[0]);
        ListNode *tmp = nullptr, *p = head;
        for (int i = 1; i <= len; i++) {
            tmp = new ListNode(arr[i]);
            p->next = tmp;
            p = p->next;
        }
        return head;
    }
};