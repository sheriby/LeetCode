#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Get a string of digits from a given string and update the pointer
     *
     * @param s The string from which to extract digits
     * @param ptr The pointer indicating the current position in the string
     * @return The extracted digits as a string
     */
    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    /**
     * Concatenate a vector of strings into a single string
     *
     * @param v The vector of strings to concatenate
     * @return The concatenated string
     */
    string getString(vector<string> &v) {
        string ret;
        for (const auto &s : v) {
            ret += s;
        }
        return ret;
    }

    /**
     * Decode a given string using a stack
     *
     * @param s The string to decode
     * @return The decoded string
     */
    string decodeString(string s) {
        vector<string> stk;  // Stack to hold the decoded strings
        size_t ptr =
            0;  // Pointer indicating the current position in the string

        while (ptr < s.size()) {  // Iterate over the string
            char cur = s[ptr];    // Get the current character

            if (isdigit(cur)) {  // If the character is a digit, extract digits
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) ||
                       cur == '[') {  // If the character is alphabetic or '[',
                                      // push it onto the stack
                stk.push_back(string(1, s[ptr++]));
            } else {  // If the character is ']', pop elements from the stack
                      // and repeat them
                ++ptr;
                vector<string> sub;  // Sub-vector to hold the elements popped
                                     // from the stack
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());  // Reverse the sub-vector
                stk.pop_back();                   // Pop the '[' from the stack
                int repTime = stoi(stk.back());   // Get the repetition count
                stk.pop_back();  // Pop the repetition count from the stack
                string t,
                    o = getString(sub);    // Get the concatenated sub-vector
                while (repTime--) t += o;  // Repeat the sub-vector
                stk.push_back(t);  // Push the repeated string onto the stack
            }
        }

        return getString(stk);  // Return the decoded string
    }
};
