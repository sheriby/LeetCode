#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int climbStairs(int n) { return climbStairsHelper(1, n); }

   private:
    // 使用递归 + 备忘录的形式
    int climbStairsHelper(int i, int n) {
        if (mp.count(i)) return mp[i];
        int res = 0;
        if (i > n) return 0;
        if (i == n) return 1;
        if (n == i + 1)
            res = 1;
        else
            res = climbStairsHelper(i + 2, n) + climbStairsHelper(i + 1, n);
        mp[i] = res;
        return res;
    }
    unordered_map<int, int> mp;
};