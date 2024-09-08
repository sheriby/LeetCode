#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, n, L, m, b;
    cin >> N;
    for (int t = 0; t < N; t++) {
        cin >> n >> L >> m >> b;
        unordered_set<int> myset;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            myset.insert(a);
        }
        // 0次跳跃
        vector<vector<int>> dp(L + 1, vector<int>(2, 0));
        dp[L][0] = 1;
        for (int j = L - 1; j >= 0; j--) {
            if (dp[j + 1][0] && myset.find(j) == myset.end()) {
                dp[j][0] = 1;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = L - 1; j >= 0; j--) {
                if (dp[j + 1][1] && myset.find(j) == myset.end()){
                    dp[j][1] = 1;
                }
                int jp = j + b;
                if (jp > L) continue;
                if (dp[jp][0])  dp[j][1] = true;
            }
            if (i == m) {
                if (dp[0][1]) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            } else {
                for (int i = 0; i <= L; i++) {
                    dp[i][0] = dp[i][1];
                    dp[i][1] = 0;
                }
            }
        }
                
    }
    return 0;
}