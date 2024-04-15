#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define Int(x) x - 'a'
class Solution {
   public:
    // abaacbabc abc
    vector<int> findAnagrams(string s, string p) {
        int len = s.size(), sublen = p.size();
        vector<int> res;
        int map[26] = {0};
        for (int i = 0; i < sublen; i++) map[Int(p[i])]++;

        int start = 0, r = 0;
        while (r < len) {
            if (map[Int(s[r])]) {
                map[Int(s[r])]--;
                if (r - start + 1 == sublen) res.push_back(start);
                r++;
            } else {
                while (start < r) {
                    map[Int(s[start])]++;
                    if (s[start++] == s[r]) break;
                }
                if (!map[Int(s[r])]) {  // 原字符串当中就没有
                    start = ++r;
                }
            }
        }
        return res;
    }
};