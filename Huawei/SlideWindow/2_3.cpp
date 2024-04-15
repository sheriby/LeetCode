#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int res = 0;
        // 存放上一次看到的字符的位置
        vector<int> hash(128, -1);
        int left = 0;
        for (int i = 0; i < len; ++i) {
            // 窗口当中已经有这个字符了
            if (hash[s[i]] >= left) {
                // 不重复的窗口为 [left, i)
                res = max(res, i - left);
                // 移动窗口到重复字符的下一个位置
                left = hash[s[i]] + 1;
            }
            // 保存位置
            hash[s[i]] = i;
        }
        res = max(res, len - left);
        return res;
    }
};