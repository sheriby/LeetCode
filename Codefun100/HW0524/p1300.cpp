#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> nums;
    int start = 0;
    int len = str.size();
    for (int i = 1; i <= len; ++i) {
        if (i == len || str[i] == ',') {
            nums.push_back(stoi(str.substr(start, i - start)));
            start = ++i;
        }
    }
    unordered_set<int> num_set;
    for (auto& n : nums) num_set.insert(n);

    int max_val = 1, max_idx = nums[0];
    for (auto& n : nums) {
        if (num_set.count(n - 1)) continue;

        int cot = 1, tmp = n;
        while (num_set.count(tmp + 1)) cot++, tmp++;
        if (cot == max_val && n < max_idx) max_idx = n;
        if (cot > max_val) {
            max_val = cot;
            max_idx = n;
        }
    }
    cout << max_idx << "," << max_val << endl;

    return 0;
}