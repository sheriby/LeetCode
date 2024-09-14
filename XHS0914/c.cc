#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<vector<pll>> edges;
vector<vector<unordered_map<ll, ll>>> vmap;
ll dfs(int x, int y, int v, vector<bool> &vis) {
    if (v == 0)
        return 1;
    if (vmap[x][y].count(v))
        return vmap[x][y][v];
    vis[y] = true;
    ll res = 0;
    for (auto &e : edges[y]) {
        int u = e.first;
        if (!vis[u]) {
            res += dfs(y, u, y ^ e.second, vis);
        }
    }
    vmap[x][y][v] = res;
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    edges.resize(n + 1);
    vmap.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        vmap[i].resize(n + 1);
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        vector<bool> vis(n + 1, false);
        cout << dfs(0, x, y, vis) << endl;
    }
    return 0;
}