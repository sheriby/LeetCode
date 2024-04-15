#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    // isPalindrome[i][j]  = ((s[i] == s[j]) && isPalindrome[i + 1][j - 1])
    // i >= j => true
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        memset(isPalindrome, 1, sizeof(isPalindrome));
        int len = s.size();
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                isPalindrome[i][j] =
                    (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
            }
        }
        backtrack(s, 0, res, {});
        return res;
    }

   private:
    bool isPalindrome[20][20] = {0};
    void backtrack(string& s, int start, vector<vector<string>>& res,
                   vector<string> path) {
        if (start == s.size()) {
            res.push_back(path);
        } else {
            for (int i = start; i < s.size(); i++) {
                if (isPalindrome[start][i]) {
                    path.push_back(s.substr(start, i - start + 1));
                    backtrack(s, i + 1, res, path);
                    path.pop_back();
                }
            }
        }
    }
};
