#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        int lens = s.size(), lent = t.size();
        if (lent > lens) return "";
        vector<int> hash(128, 0);
        vector<bool> has(128);
        for (int i = 0; i < lent; ++i) {
            hash[t[i]]++;
            has[t[i]] = true;
        }

        int left = 0, start = -1, min_val = 0x7fffffff;
        for (int i = 0; i < lens; ++i) {
            if (has[s[i]]) {
                hash[s[i]]--;
                if (allZero(hash)) {
                    while (left < i) {
                        if (!has[s[left]])
                            left++;
                        else if (hash[s[left]] < 0) {
                            hash[s[left]]++;
                            left++;
                        } else
                            break;
                    }
                    if (i - left + 1 < min_val) {
                        min_val = i - left + 1;
                        start = left;
                    }
                }
            }
        }
        if (start == -1) return "";
        return s.substr(start, min_val);
    }

   private:
    bool allZero(vector<int>& nums) {
        int len = nums.size();
        for (int i = 'A'; i <= 'Z'; ++i) {
            if (nums[i] > 0) return false;
        }
        for (int i = 'a'; i <= 'z'; ++i) {
            if (nums[i] > 0) return false;
        }
        return true;
    }
};