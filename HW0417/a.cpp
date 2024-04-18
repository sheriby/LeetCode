#include <bits/stdc++.h>
using namespace std;

int del3(vector<string>& nums) {
    if (nums.size() < 3) return 0;
    vector<string> res;
    int cnt = 0;
    int idx = 0;
    while (idx < nums.size()) {
        if (idx < nums.size() - 2 && nums[idx] == nums[idx + 1] &&
            nums[idx] == nums[idx + 2]) {
            idx = idx + 3;
            cnt++;
        } else {
            res.push_back(nums[idx]);
            idx++;
        }
    }
    nums.resize(res.size());
    for (int i = 0; i < res.size(); ++i) {
        nums[i] = res[i];
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    while (del3(nums))
        ;
    if (!nums.size())
        cout << 0 << endl;
    else {
        for (int i = 0; i < nums.size() - 1; i++) cout << nums[i] << " ";
        cout << nums.back() << endl;
    }

    return 0;
}