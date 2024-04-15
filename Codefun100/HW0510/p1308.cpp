#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) edge[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        edge[s][e] = w;
    }
    int start;
    cin >> start;
    // 除起点以外，所有的结点的自环的权重加到目标是该节点的边当中去
    for (int i = 1; i <= n; ++i) {
        if (i != start && edge[i][i] != 0) {
            for (int j = 1; j <= n; ++j) {
                if (i != j && edge[j][i] != INF) edge[j][i] += edge[i][i];
            }
            edge[i][i] = 0;
        }
    }
    // flody求图当中任意两个点的最近距离
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }

    int res = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (edge[start][i] != INF) {
            cnt++;
            res = max(res, edge[start][i]);
        }
    }
    cout << cnt << endl;
    cout << res << endl;

    return 0;
}