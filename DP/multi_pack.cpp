/*
有N种物品和一个容量是V的背包。第i种物品最多有si件，每件体积是vi，价值是wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。输出最大价值。
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, v;
    cin >> n >> v;
    vector<int> weight(n * 11 + 1), value(n * 11 + 1);
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        int _weight, _value, _sum;
        cin >> _weight >> _value >> _sum;
        int k = 1;
        while (k <= _sum) {
            weight[cnt] = _weight * k;
            value[cnt++] = _value * k;
            _sum -= k;
            k *= 2;
        }
        if (_sum > 0) {
            weight[cnt] = _weight * _sum;
            value[cnt++] = _value * _sum;
        }
    }

    vector<int> dp(v + 1);

    for (int i = 1; i < cnt; ++i)
        for (int j = v; j >= weight[i]; --j)
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

    cout << dp[v] << endl;

    return 0;
}