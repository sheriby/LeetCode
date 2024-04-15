#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        unordered_map<Node*, Node*> map;
        Node *newHead = nullptr, *p = nullptr;

        p = new Node(head->val);
        p->next = head->next;
        p->random = head->random;
        map.insert({head, p});
        newHead = p;
        head = head->next;

        while (head) {
            p->next = new Node(head->val);
            p = p->next;
            p->next = nullptr;
            p->random = head->random;
            map.insert({head, p});
            head = head->next;
        }
        p = newHead;
        while (p) {
            p->random = map[p->random];
            p = p->next;
        }
        return newHead;
    }
};