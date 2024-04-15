#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> st;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else {
                if (st.empty()) return false;
                char c = st.top();
                if ((s[i] == ')' && c == '(') || (s[i] == ']' && c == '[') ||
                    (s[i] == '}' && c == '{'))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};