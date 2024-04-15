#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        int len = len1 + len2;
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> res(len, 0);
        // 第i位和第j位相乘的结果在新数的第i+j+1当中
        for (int i = len1 - 1; i >= 0; --i) {
            int x = num1[i] - '0';
            for (int j = len2 - 1; j >= 0; --j) {
                int y = num2[j] - '0';
                res[i + j + 1] += x * y;
            }
        }

        // 统一来处理进位的情况
        for (int i = len - 1; i > 0; --i) {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }

        // 将数组转为字符串
        string ans;
        ans.reserve(len);
        bool flag = false;
        for (int i = 0; i < len; ++i) {
            if (res[i] == 0 && !flag) continue;
            flag = true;
            ans.push_back(res[i] + '0');
        }
        return ans;
    }
};