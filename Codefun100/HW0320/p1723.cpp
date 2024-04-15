#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges(100001, vector<int>());
vector<int> visited(100001, false);
stack<int> stk;

bool dfs(int u) {
    stk.push(u);
    visited[u] = 1;

    for (auto v : edges[u]) {
        if (visited[v] == 1) {
            stk.push(v);
            return true;
        } else if (dfs(v))
            return true;
    }

    stk.pop();
    visited[u] = 2;
    return false;
}

// 找到有向图当中的环
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int n, s;
        cin >> n >> s;
        edges[s].resize(n - 1);
        for (int j = 0; j < n - 1; ++j) cin >> edges[s][j];
    }

    for (int i = 1; i <= 100001; ++i) {
        if (!visited[i] && dfs(i)) {
            int top = stk.top();
            cout << top << " ";
            stk.pop();
            while (stk.size() && stk.top() != top) {
                cout << stk.top() << " ";
                stk.pop();
            }
            cout << top << endl;
            break;
        }
    }
    return 0;
}