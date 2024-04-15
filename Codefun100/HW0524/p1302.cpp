#include <bits/stdc++.h>
using namespace std;

inline int left(int i) { return 2 * i + 1; }
inline int right(int i) { return 2 * i + 2; }

vector<int> nums;
int n;
unordered_map<int, int> mp;
unordered_map<int, int> nmp;

int max_profit_without_root(int);

int max_profit(int root) {
    if (!nums[root]) return 0;            // 该节点不存在
    if (mp.count(root)) return mp[root];  // 已经计算过了
    int profit = nums[root];  // 计算删除根节点的最大利润
    if (left(root) < n)
        profit += max_profit_without_root(left(root));  // 不维护左右节点
    if (right(root) < n) profit += max_profit_without_root(right(root));
    profit =
        max(profit, max_profit_without_root(root));  // 计算两个利润之间的最大值
    mp[root] = profit;
    return profit;
}

int max_profit_without_root(int root) {
    if (!nums[root]) return 0;
    if (nmp.count(root)) return nmp[root];
    int profit = 0;  // 不维护根节点
    if (left(root) < n) profit += max_profit(left(root));
    if (right(root) < n) profit += max_profit(right(root));
    nmp[root] = profit;
    return profit;
}

int main() {
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << max_profit(0) << endl;  // 返回维护根节点和不维护根节点的最大值
    return 0;
}