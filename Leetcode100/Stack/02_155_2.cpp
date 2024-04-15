#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        min_val = min(val, min_val);
        st.push(val);
        min_st.push(min_val);
    }

    void pop() {
        st.pop();
        min_st.pop();
        if (st.empty()) {
            min_val = 0x7fffffff;
        } else {
            min_val = min_st.top();
        }
    }

    int top() { return st.top(); }

    int getMin() { return min_val; }

   private:
    stack<int> st;
    stack<int> min_st;
    int min_val = 0x7fffffff;
};
