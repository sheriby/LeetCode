#include <bits/stdc++.h>
using namespace std;
int n, k;
string ops;
int res = 0;
const int MOD = 1e9 + 7;

// 最暴力的回溯
void dfs(int idx, int val) {
    if (idx == n) {
        res++;
        res %= MOD;
        return;
    }
    if (idx == 0) {
        for (int i = 1; i <= k; ++i) {
            dfs(idx + 1, i);
        }
        return;
    }

    char op = ops[idx - 1];
    for (int i = 1; i <= k; ++i) {
        switch (op) {
            case '>':
                if (i > val) dfs(idx + 1, i);
                break;
            case '<':
                if (i < val) dfs(idx + 1, i);
                break;
            case '=':
                if (i == val) dfs(idx + 1, i);
                break;
        }
    }
}

int main() {
    cin >> n >> k;
    cin >> ops;
    dfs(0, 0);
    cout << res << endl;
    return 0;
}