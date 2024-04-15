#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    // dp[i] = dp[i-1] + dp[i-2], dp[n] = 0;
    // 只和前两个状态有关，可以优化
    // pre = cur + nxt
    //         pre cur nxt
    // cur+nxt  pre nxt
    int climbStairs(int n) {
        int cur = 1, pre = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = cur;
            cur += pre;
            pre = tmp;
        }
        return cur;
    }
};