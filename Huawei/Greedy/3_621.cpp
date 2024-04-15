#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> arr(26, 0);
        vector<int> t(26, 0);
        int len = tasks.size();
        if (!n) return len;
        for (int i = 0; i < len; ++i) arr[tasks[i] - 'A']++;
        int cnt = 0, res = 0;
        while (cnt < len) {
            int idx = findMax(arr, t);
            // 找到可以安排的任务了
            if (idx != -1) {
                // 设置成n+1是因为后面要处理间隔
                t[idx] = n + 1;
                --arr[idx];
                ++cnt;
            }
            for (int i = 0; i < 26; ++i) t[i] = max(0, t[i] - 1);
            ++res;
        }

        return res;
    }

   private:
    int findMax(vector<int>& arr, vector<int>& t) {
        int max_i = -1, max_v = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (t[i]) continue;
            if (arr[i] > max_v) {
                max_v = arr[i];
                max_i = i;
            }
        }
        return max_i;
    }
};