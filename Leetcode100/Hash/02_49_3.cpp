#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto str : strs) {
            string key = to_standard(str);
            map[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = map.begin(); it != map.end(); it++) {
            ans.emplace_back(it->second);
        }
        return ans;
    }

   private:
    string to_standard(string& str) {
        int chars[26] = {0};
        for (auto& i : str) {
            chars[i - 'a']++;
        }
        string res = "";
        for (int i = 0; i < 26; i++) {
            if (chars[i] != 0) {
                res += 'a' + i;
                res += to_string(chars[i]);
            }
        }
        return res;
    }
};