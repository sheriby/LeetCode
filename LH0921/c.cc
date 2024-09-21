#include <bits/stdc++.h>
using namespace std;

int max_val = 0;
int n, X, Y, A, B;

// 12%
int dfs(int node, vector<vector<int>> &child, vector<vector<int>> &nodeval) {
    int cur_val = 0;
    int type = nodeval[node][0], consume = nodeval[node][1],
        gain = nodeval[node][2];
    if (type == 0) {
        if (A < consume * X) {
            return cur_val;
        } else {
            A -= consume * X;
            cur_val += gain;
        }
        int max_child = 0;
        for (int c : child[node]) {
            // max_child = max(dfs(c, child, nodeval, a, b), max_child);
            max_child += dfs(c, child, nodeval);
        }
        cur_val += max_child;
        return cur_val;
    } else {
        if (A < consume * Y && B < consume) {
            return cur_val;
        } else {
            int cura_val = cur_val, curb_val = cur_val;
            if (A >= consume * Y) {
                A -= consume * Y;
                cura_val += gain;
                int max_child = 0;
                for (int c : child[node]) {
                    // max_child = max(dfs(c, child, nodeval, a, b), max_child);
                    max_child += dfs(c, child, nodeval);
                }
                cura_val += max_child;
            }
            if (B >= consume) {
                if (B >= consume * Y) {
                    A += consume * Y;
                }
                B -= consume;
                curb_val += gain;
                int max_child = 0;
                for (int c : child[node]) {
                    max_child += dfs(c, child, nodeval);
                }
                curb_val += max_child;
            }
            cur_val = max(cura_val, curb_val);
            return cur_val;
        }
    }
}

int main() {
    cin >> n >> X >> Y >> A >> B;
    vector<vector<int>> child(n + 1);
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        child[x].push_back(i);
    }
    vector<vector<int>> nodeval(n + 1, vector<int>(3));
    for (int i = 1; i <= n; ++i) {
        cin >> nodeval[i][0] >> nodeval[i][1] >> nodeval[i][2];
    }
    for (int i = 1; i <= n; ++i) {
        sort(child[i].begin(), child[i].end(),
             [&](int a, int b) { return nodeval[a][2] > nodeval[b][2]; });
    }
    cout << dfs(1, child, nodeval) << endl;

    return 0;
}