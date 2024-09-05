#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> map(m);
    for (int i = 0; i < m; ++i) {
        cin >> map[i];
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = m-1; i >= 0; --i) {
        for (int j = n-1; j >= 0; --j) {
            dp[i][j] = (map[i][j] >= 'A' && map[i][j] <= 'Z') ? 1 : 0;
            dp[i][j] += max(dp[i + 1][j] , dp[i][j + 1]);
        }
    }
    
    cout << dp[0][0] << endl;
    return 0;
}