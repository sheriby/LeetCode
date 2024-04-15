#include <bits/stdc++.h>
using namespace std;
vector<int> like;
vector<int> comment;
int max_val;
int n, k;

// 暴力枚举
void dfs(int idx, int cnt, int sum_like, int min_com) {
    if (cnt == k) max_val = max(max_val, sum_like * min_com);
    if (idx == n) return;
    dfs(idx + 1, cnt + 1, sum_like + like[idx], min(min_com, comment[idx]));
    dfs(idx + 1, cnt, sum_like, min_com);
}

int main() {
    cin >> n >> k;
    like.resize(n), comment.resize(n);
    for (int i = 0; i < n; ++i) cin >> like[i];
    for (int i = 0; i < n; ++i) cin >> comment[i];
    // sum(like) * min(comment)
    // 回溯
    dfs(0, 0, 0, 0x3f3f3f3f);
    cout << max_val << endl;
    return 0;
}