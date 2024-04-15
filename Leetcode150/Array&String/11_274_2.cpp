#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 3 0 6 1 5
    // 6 5 3 1 0
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector<int> cot(len + 1, 0);
        for (int i = 0; i < len; i++) {
            if (citations[i] >= len)
                cot[len]++;
            else
                cot[citations[i]]++;
        }
        int cur = 0;
        for (int i = len; i >= 0; i--) {
            cur += cot[i];
            if (cur >= i) return i;
        }
        return len;
    }
};