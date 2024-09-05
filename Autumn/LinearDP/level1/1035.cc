#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> scores(n + 2, 0);
    for (int i = 1; i <= n; ++i) cin >> scores[i];
    // 说到底就是只能跳过一个或者两个格子，因为分数没有负值，跳过三个格子相当于亏一个格子
    // 一个格子的分数由其前面的第二个和第三个格子来决定
    if (n == 1) return 0; // 跳不了一点
    vector<int> dp(n + 2, 0);
    dp[1] = scores[1];
    dp[2] = scores[2];
    for (int i = 3; i <= n + 1; ++i) {
        dp[i] = max(dp[i - 2], dp[i - 3]) + scores[i];
    }
    cout << dp[n + 1] << endl;
    return 0;
}