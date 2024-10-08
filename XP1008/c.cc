#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     * @param node ListNode类
     * @param n int整型
     * @return ListNode类
     */
    ListNode *removeNode(ListNode *node, int n) {
        int len = 0;
        ListNode *p = node;
        while (p) {
            len++;
            p = p->next;
        }
        if (n > len)
            return node;
        n = len - n;
        if (n == 0)
            return node->next;
        p = node;
        for (int i = 0; i < n - 1; ++i)
            p = p->next;
        p->next = p->next->next;
        return node;
    }
};
