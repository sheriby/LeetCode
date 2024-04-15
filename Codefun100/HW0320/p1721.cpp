#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

int main() {
    int m, n, x;
    cin >> m >> n >> x;
    vector<PII> arr(x + 1);
    for (int i = 0; i < x; ++i) cin >> arr[i].first >> arr[i].second;

    int max_val = -1;

    /* 一种比较nb的二进制暴力遍历 if x = 2 => 00 01 10 11
    for (int i = 0; i < (1 << x); ++i) {
        for (int j = 0; j < x; ++j) {
            if (i >> j & 1) {
                // code here
            }
        }
    }
    */
    for (int i = 0; i < (1 << x); ++i) {  // 00 01 10 11
        vector<int> cnt(n + 1, 0);
        int res = 0;
        bool flag = true;
        for (int j = 0; j < x; ++j) {
            if (i >> j & 1) {  // i的第j位是1
                for (int k = arr[j].first; k < arr[j].second; ++k) ++cnt[k];
                res += arr[j].second - arr[j].first;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (cnt[j] > m) {
                flag = false;
                break;
            }
        }
        if (flag) max_val = max(max_val, res);
    }
    cout << max_val << endl;
    return 0;
}
// 01 38 19 010