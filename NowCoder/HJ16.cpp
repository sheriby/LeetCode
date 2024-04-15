#include <bits/stdc++.h>
using namespace std;

#define VALUE(i) (prices[i] * importance[i])

int main() {
    int money, n;
    cin >> money >> n;
    vector<int> prices(n + 1), importance(n + 1), attach(n + 1);
    // 通过主件可以迅速的找到附件
    vector<vector<int>> attachs(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        cin >> prices[i] >> importance[i] >> attach[i];
        attachs[attach[i]].push_back(i);
    }
    // 是不是可以转化为背包问题？ 附件比较难以处理
    // 可以想想完全背包问题或多重背包问题的时候，是怎么处理的，想办法将其转化为01背包的问题
    // 主件 主件+附件1 主件+附件2 主件+附件1+附件2 将这四种情况全都加入背包当中
    // dp[i][j] = max(dp[i-1][j], dp[i][j-p[i]] + p[i]*i[i])
    vector<int> dp(money + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = money; j >= prices[i]; --j) {
            // 附件不能单独放背包
            if (attach[i]) continue;
            // 普通的背包情况
            dp[j] = max(dp[j], dp[j - prices[i]] + VALUE(i));
            // 两个附件分别放背包
            for (int k = 0; k < attachs[i].size(); k++) {
                int a = attachs[i][k];
                int p = prices[i] + prices[a];
                int v = VALUE(i) + VALUE(a);
                if (j >= p) dp[j] = max(dp[j], dp[j - p] + v);
            }
            // 两个附件全部放背包
            if (attachs[i].size() == 2) {
                int a1 = attachs[i][0], a2 = attachs[i][1];
                int p = prices[i] + prices[a1] + prices[a2];
                int v = VALUE(i) + VALUE(a1) + VALUE(a2);
                if (j >= p) dp[j] = max(dp[j], dp[j - p] + v);
            }
        }
    }
    cout << dp[money] << endl;

    return 0;
}