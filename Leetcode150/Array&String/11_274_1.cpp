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
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < len; i++)
            if (citations[i] == i + 1)
                return i + 1;
            else if (citations[i] < i + 1)
                return i;
    }
};