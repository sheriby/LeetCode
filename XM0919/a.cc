#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int flag = true;
        int N, n, c;
        cin >> N >> n >> c;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int val = arr[i];
            for (int j = N; j >= 0; --j) {
                if (dp[j] && j + val <= N) {
                    dp[j + val] = 1;
                }
            }
        }
        for (int i = N - c; i <= N; ++i) {
            if (dp[i]) {
                cout << "YES" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "NO" << endl;
    }
    return 0;
}