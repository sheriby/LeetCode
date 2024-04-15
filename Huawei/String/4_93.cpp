#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> path;
        dfs(s, 0, path);
        return res;
    }

   private:
    vector<string> res;
    void dfs(string s, int idx, vector<string>& path) {
        if (path.size() == 4) {
            // 字符用完，解析正确
            if (idx == s.size()) {
                string tmp;
                for (int i = 0; i < 4; ++i) {
                    tmp += path[i] + '.';
                }
                tmp.pop_back();
                res.push_back(tmp);
            }
            return;
        }

        // 0开头那么只能是0
        if (s[idx] == '0') {
            path.push_back("0");
            dfs(s, idx + 1, path);
            path.pop_back();
            return;
        }

        for (int j = 1; j <= 3 && idx + j <= s.size(); ++j) {
            int num = stoi(s.substr(idx, j));
            if (num >= 0 && num <= 255) {
                path.push_back(s.substr(idx, j));
                dfs(s, idx + j, path);
                path.pop_back();
            }
        }
    }
};