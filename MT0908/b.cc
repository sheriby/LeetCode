#include <bits/stdc++.h>
using namespace std;

inline long long Cn2(int n) {
    return (long long)n * (n - 1) / 2;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long ans = 0;
        int n;
        cin >> n;
        vector<int> vis(n + 1, 0);
        vector<vector<int>> edges(n + 1, vector<int>());
        unordered_map<int, int> m;
        for (int j = 0; j < n - 1; j++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        queue<int> q;
        q.push(1);
        while (q.size()) {
            int u = q.front();
            q.pop();
            vis[u] = 1;
            int son = 0;
            for (int v : edges[u]) {
                if (vis[v] == 0) {
                    q.push(v);
                    son++;
                }
            }
            m[son]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            ans += Cn2(it->second);
        }
        cout << ans << endl;
    }
    return 0;
}