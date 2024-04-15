#include <bits/stdc++.h>
using namespace std;

// 要填充的地方不能有些地方已经被填充过了
bool isAvailable(vector<vector<bool>> &rect, int x, int y, int k) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (rect[x + i][y + j]) return false;
        }
    }
    return true;
}

// 将该区域填充或取消填充
void fillUp(vector<vector<bool>> &rect, int x, int y, int k, bool val) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            rect[x + i][y + j] = val;
        }
    }
}

int ans;
// 回溯强搜，确实顶级
// (x,y)开始检查是否可以填充，从最大的开始填充直到填充完所有的位置
void dfs(int x, int y, vector<vector<bool>> &rect, int cnt) {
    int n = rect.size(), m = rect[0].size();
    if (cnt >= ans) {  // 剪枝，这种填充的方法可以比目前最好的要差了
        return;
    }
    if (x >= n) {  // 填充完毕
        ans = cnt;
        return;
    }
    if (y >= m) {  // 填充下一行
        dfs(x + 1, 0, rect, cnt);
        return;
    }
    /* 如当前已经被覆盖，则直接尝试下一个位置 */
    if (rect[x][y]) {
        dfs(x, y + 1, rect, cnt);
        return;
    }

    int len = min(n - x, m - y);  // 计算当前能填充的最大的正方形的大小
    while (len >= 1 && !isAvailable(rect, x, y, len)) {
        len--;
    }
    // 从大到小开始尝试填充
    for (int k = len; k >= 1; k--) {
        /* 将长度为 k 的正方形区域标记覆盖 */
        fillUp(rect, x, y, k, true);
        /* 跳过 k 个位置开始检测 */
        dfs(x, y + k, rect, cnt + 1);
        // 回溯，取消填充
        fillUp(rect, x, y, k, false);
    }
}

int tilingRectangle(int n, int m) {
    ans = max(n, m);  // 需要证明
    vector<vector<bool>> rect(n, vector<bool>(m, false));
    dfs(0, 0, rect, 0);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << tilingRectangle(n, m) << endl;
}
