#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int f[MAXN];

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}

void _union(int x, int y) { f[find(x)] = find(y); }

bool same(int x, int y) { return find(x) == find(y); }

// ac
int main() {
    int N, M, T;
    cin >> N >> M >> T;
    vector<unordered_set<int>> edges(N + 1, unordered_set<int>());
    for (int i = 1; i <= N; ++i) {
        f[i] = i;
    }
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        _union(a, b);
        _union(a, c);
        edges[a].insert(b);
        edges[a].insert(c);
        edges[b].insert(a);
        edges[b].insert(c);
        edges[c].insert(a);
        edges[c].insert(b);
    }

    for (int i = 0; i < T; ++i) {
        int a, b;
        cin >> a >> b;
        if (edges[a].count(b)) {
            cout << 1 << endl;
        } else if (same(a, b)) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    }
    return 0;
}