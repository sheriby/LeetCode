#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // -1 1 2 1 -1   2
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int cot = 0;
        int f[20001] = {0}, cur = 0;
        for (int i = 0; i < len; i++) {
            cur += nums[i];
            f[i] = cur;
            if (f[i] == k) cot++;
        }

        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                if (f[j] - f[i] == k) cot++;

        return cot;
    }
};