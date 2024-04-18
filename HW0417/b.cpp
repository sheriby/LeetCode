#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

vector<vector<int>> edges;
vector<int> small;
vector<int> big;
unordered_set<int> root;
vector<string> fathers;
vector<bool> vis;

int dfs(int i) {
    vis[i] = true;
    int res = 5 * big[i] + 2 * small[i];
    for (int e : edges[i]) {
        if (!vis[e]) {
            res += dfs(e);
        }
    }
    return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    fathers.resize(n);
    small.resize(n);
    big.resize(n);
    edges.resize(n);
    vis = vector<bool>(n, false);
    int idx = 0;
    string name, father;
    int b, s;
    for (int i = 0; i < n; i++) {
        cin >> name >> father >> b >> s;
        if (!mp.count(name)) mp[name] = idx++;

        int _i = mp[name];
        if (father == "*")
            root.insert(_i);
        else
            fathers[_i] = father;
        if (b)
            small[_i] = s;
        else
            big[_i] = s;
    }

    for (int i = 0; i < idx; i++) {
        if (fathers[i] == "") continue;
        int to = mp[fathers[i]];
        edges[to].push_back(i);
    }
    int ans = 0;
    for (int i : root) {
        if (dfs(i) > m) ans++;
    }
    cout << ans << endl;

    return 0;
}