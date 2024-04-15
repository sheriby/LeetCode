#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // ababca defd g h
    vector<int> partitionLabels(string s) {
        int len = s.size();
        int map[26] = {0};
        for (int i = 0; i < len; i++) {
            map[s[i] - 'a'] = i;
        }
        vector<int> res;
        int start = 0, last = -1;
        for (int i = 0; i < len; i++) {
            last = max(last, map[s[i] - 'a']);
            if (i == last) {
                res.push_back(last - start + 1);
                last = -1;
                start = i + 1;
            }
        }
        return res;
    }
};