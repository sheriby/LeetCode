#include <bits/stdc++.h>
using namespace std;
#define int long long

int get_cost(string& str, int idx) {
    return abs(str[idx] - 'P') + abs(str[idx + 1] - 'D') +
           abs(str[idx + 2] - 'D');
}

int32_t main() {
    const int INF = LONG_LONG_MAX / 2;
    int n;
    string str;
    cin >> n >> str;
    vector<int> cost(n);
    for (int i = 0; i + 2 < n; ++i) cost[i] = get_cost(str, i);
    vector<int> dp(n + 3, INF);
    for (int i = n - 1; i >= 0; --i) {
        if ((n - i) % 3 == 0) {
            if (i + 3 < n)
                dp[i] = cost[i] + dp[i + 3];
            else
                dp[i] = cost[i];
        } else {
            dp[i] = min(dp[i + 1], cost[i] + dp[i + 3]);
        }
    }
    cout << n / 3 << " " << dp[0] << endl;
}