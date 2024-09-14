#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> vip(4);
    vector<int> vip_days = {1, 30, 365, 3650};
    for (int i = 0; i < 4; ++i)
        cin >> vip[i];
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    vector<ll> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + arr[i];
        for (int v = 0; v < 4; ++v) {
            int t = max(i - vip_days[v], 0);
            dp[i] = min(dp[i], dp[t] + vip[v]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}