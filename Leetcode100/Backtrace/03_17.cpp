#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string m[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        string path;
        dfs(digits, path, 0);
        return res;
    }

   private:
    vector<string> res;
    void dfs(string digits, string path, int index) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        string str = m[digits[index] - '2'];
        for (int i = 0; i < str.size(); i++) {
            path.push_back(str[i]);
            dfs(digits, path, index + 1);
            path.pop_back();
        }
    }
};