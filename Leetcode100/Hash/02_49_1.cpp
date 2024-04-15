#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>> res;
        vector<pair<string, string>> pairs;
        for (int i = 0; i < len; i++)
            pairs.push_back(make_pair(to_standard(strs[i]), strs[i]));

        sort(pairs.begin(), pairs.end(),
             [](auto a, auto b) { return a.first < b.first; });

        int i = 0;
        while (i < len) {
            vector<string> same;
            same.push_back(pairs[i].second);
            int j;
            for (j = i + 1; j < len; j++) {
                if (pairs[j].first == pairs[i].first)
                    same.push_back(pairs[j].second);
                else
                    break;
            }
            i = j;
            res.push_back(same);
        }
        return res;
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

void print_arr(vector<string>& arr) {
    cout << "[";
    for (auto a : arr) {
        cout << a << ",";
    }
    cout << "]" << endl;
}

int main(int argc, char const* argv[]) {
    vector<string> strs = {""};
    print_arr(strs);
    Solution s = Solution();
    auto arrs = s.groupAnagrams(strs);
    for (auto arr : arrs) {
        print_arr(arr);
    }
    return 0;
}
