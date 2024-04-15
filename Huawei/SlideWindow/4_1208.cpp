#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int res = 0, left = 0;
        for (int i = 0; i < len; ++i) {
            maxCost -= abs(s[i] - t[i]);
            if (maxCost >= 0) {
                res = max(res, i - left + 1);
            } else {
                for (int j = left; j <= i; ++j) {
                    maxCost += abs(s[j] - t[j]);
                    left = j + 1;
                    if (maxCost >= 0) {
                        res = max(res, i - left + 1);
                        break;
                    }
                }
            }
        }
        return res;
    }
};