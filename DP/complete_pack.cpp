/*
有N种物品和一个容量是V的背包，每种物品都有无限件可用。第i种物品的体积是
vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。
*/
#include <iostream>
#include <vector>
using namespace std;

// 完全背包问题，每个物品可以选很多次，可以将物品分成 vi*2^k，wi*2^k，其中
// vi*2^k < v 利用这点可以将完全背包转化为01背包问题
// dp[i][j] = max(dp[i-1][j], dp[i][j-wi[i]] +
// v[i]])，这里是dp[i][j-wi[i]]是因为此时i物品也还是能选的 转换为一维 dp[j] =
// max(dp[j], dp[j-wi[i]] + v[i]), 和01背包的区别是此时要正序
int main() {
    int n, v;
    cin >> n >> v;
    vector<int> weight(n + 1), value(n + 1);
    for (int i = 1; i <= n; ++i) cin >> weight[i] >> value[i];

    vector<int> dp(v + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int k = 1; k * weight[i] <= v; k *= 2)
            for (int j = k * weight[i]; j <= v; ++j)
                dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);

    cout << dp[v] << endl;

    return 0;
}