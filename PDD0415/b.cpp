#include <bits/stdc++.h>
using namespace std;

int n;
int sum_val = 0;
const int mod = 1e7 + 7;
vector<vector<bool>> dp;

int mod_plus(int a, int b) { return (a + b) % mod; }
int mod_minus(int a, int b) { return (a - b + mod) % mod; }

int get_score(vector<int>& arr, int from, int len, vector<int>& pre_nums) {
    if (!dp[from][from + len - 1]) return 0;
    return mod_minus(pre_nums[from + len], pre_nums[from]);
}

int main() {
    cin >> n;
    vector<int> nums(n);
    vector<int> pre_nums(n + 1);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    pre_nums[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre_nums[i] = mod_plus(pre_nums[i - 1], nums[i - 1]);
    }
    dp = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) dp[i][i] = true;
    for (int i = 0; i < n - 1; ++i)
        if (nums[i] != nums[i + 1]) dp[i][i + 1] = true;

    for (int l = 3; l <= n; l++) {
        for (int i = 0; i + l <= n; i++) {
            dp[i][i + l - 1] = dp[i][i + l - 2] && dp[i + 1][i + l - 1] &&
                               nums[i + l - 1] != nums[i + l - 2];
        }
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l <= n; i++) {
            sum_val = mod_plus(sum_val, get_score(nums, i, l, pre_nums));
        }
    }
    cout << sum_val << endl;
    return 0;
}