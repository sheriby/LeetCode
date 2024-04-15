#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        Node* q = head;
        while (q->next && q->next->val < val) {
            q = q->next;
        }
        Node* p = new Node();
        p->val = val;
        p->next = q->next;
        q->next = p;
    }

    void pop() {
        Node* q = head;
        while (q->next && q->next->val != st.top()) {
            q = q->next;
        }
        q->next = q->next->next;
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return head->next->val; }

   private:
    stack<int> st;
    Node* head = new Node();
};