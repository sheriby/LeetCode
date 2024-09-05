#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, g;
    cin >> n >> m >> g;
    vector<vector<int>> cmap(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> cmap[i][j];
    
    // (i, j)肯定是由(i-1, j)或者(i, j-1)移动而得来
    // 计算每一个点的最大的价值
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + cmap[i][j];
        }
    }
    // 找到符合给定价值的离起点最近的位置
    int min_len = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j] >= g) min_len = min(min_len, i + j - 2);
        }
    }
    cout << min_len << endl;
    return 0;
}