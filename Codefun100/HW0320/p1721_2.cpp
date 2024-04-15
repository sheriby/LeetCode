#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

vector<PII> arr;
int m, n, x;
int max_val = 0;

// 判读当前的乘坐是否是合法的
bool is_valid(vector<int> path) {
    for (int i = 0; i < n; ++i) {
        if (path[i] > m) return false;
    }
    return true;
}

// 利用回溯来遍历
void dfs(int idx, int val, vector<int>& path) {
    if (is_valid(path))
        max_val = max(max_val, val);
    else
        return;
    if (idx >= x) return;
    int start = arr[idx].first, end = arr[idx].second;
    for (int i = start; i < end; ++i) ++path[i];
    dfs(idx + 1, val + end - start, path);
    for (int i = start; i < end; ++i) --path[i];
    dfs(idx + 1, val, path);
}

int main() {
    // 2 11 4
    cin >> m >> n >> x;
    arr.resize(x);
    for (int i = 0; i < x; ++i) cin >> arr[i].first >> arr[i].second;
    vector<int> path(n, 0);
    dfs(0, 0, path);
    cout << max_val << endl;
    return 0;
}