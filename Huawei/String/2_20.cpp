#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> st;

        for (int i = 0; i < len; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else {
                if (st.empty()) return false;
                if (s[i] == ']' && st.top() != '[') return false;
                if (s[i] == ')' && st.top() != '(') return false;
                if (s[i] == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};