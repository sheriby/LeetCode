/*
有N种物品和一个容量是V的背包，每种物品都有无限件可用。第i种物品的体积是
vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。
*/
#include <iostream>
#include <vector>
using namespace std;

// 完全背包问题，每个物品可以选很多次，可以将物品分成 vi*2^k，wi*2^k，其中
// 完全背包和01背包的唯一区别就是完全背包是正序，01背包是反序
int main() {
    int n, v;
    cin >> n >> v;
    vector<int> weight(n + 1), value(n + 1);
    for (int i = 1; i <= n; ++i) cin >> weight[i] >> value[i];

    vector<int> dp(v + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int j = weight[i]; j <= v; ++j)
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

    cout << dp[v] << endl;

    return 0;
}