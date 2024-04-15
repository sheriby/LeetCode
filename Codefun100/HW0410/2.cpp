#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& f, int x) {
    if (f[x] == x) return x;
    f[x] = find(f, f[x]);
    return f[x];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> edges[i][j];
        }
    }
    vector<int> f(n);
    for (int i = 0; i < n; ++i) f[i] = i;

    vector<int> point_val(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (edges[i][j] && find(f, i) != find(f, j))
                f[find(f, j)] = find(f, i);
            point_val[i] += edges[i][j];
        }
    }

    // ABC BE
    vector<int> sum(n);
    for (int i = 0; i < n; ++i) {
        sum[f[i]] += point_val[i];
    }

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (sum[i] != 0) res.push_back(sum[i]);
    }
    sort(res.begin(), res.end(), std::greater<int>());
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}