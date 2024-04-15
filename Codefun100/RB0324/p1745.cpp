#include <bits/stdc++.h>
using namespace std;

#define int long long

int max_val;
int sum_val;

int check(vector<int>& nums, int idx) {
    int tmp = nums[idx];
    int target = nums[idx];
    int max_tmp = max_val;
    if (target == max_val) return sum_val;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == idx) continue;
        q.push(nums[i]);
    }
    while (target < max_tmp) {
        int f = q.top();
        if (target >= f) {
            target = max_tmp;
            break;
        }
        // 最大和最小都一样大
        // 1 5 5 5
        // 4 6 6 6
        if (f == max_tmp) {
            int len = nums.size() - 1;
            while (target < max_tmp) {
                target++;
                if (target >= max_tmp) break;
                max_tmp++;
                bool flag = false;
                for (int k = 0; k < len - 1; k++) {
                    target++;
                    if (target >= max_tmp) flag = true;
                }
                if (flag) break;
            }
            break;
        } else {
            int minus = max_tmp - f;
            f += minus;
            target += minus;
        }
        q.pop();
        q.push(f);
    }
    int op = target - tmp - 1;
    return sum_val + target - tmp + op;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    if (n == 1) {
        cout << nums[0] << endl;
        return 0;
    }
    if (n == 2) {
        int sum = nums[0] + nums[1];
        if (nums[0] > nums[1])
            cout << sum << endl << -1 << endl;
        else if (nums[0] == nums[1])
            cout << sum << endl << sum << endl;
        else
            cout << -1 << endl << sum << endl;
    }
    max_val = *max_element(nums.begin(), nums.end());
    sum_val = accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < n; ++i) {
        cout << check(nums, i) << endl;
    }

    return 0;
}
// 1 3 4 => 1 7
// 最大和最小的差