#include <bits/stdc++.h>
using namespace std;

int mp[10001][10001];

int cap[10001];

int dis[10001];

bool vis[10001];

const int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] == -1) mp[i][j] = INF;
        }
    }
    for (int i = 0; i < n; ++i) cin >> cap[i];
    int err, errc;
    cin >> err >> errc;
    for (int i = 0; i < n; ++i) {
        dis[i] = INF;
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, err});

    while (q.size()) {
        int node = q.top().second, d = q.top().first;
        q.pop();
        if (vis[node]) continue;
        vis[node] = true;
        for (int i = 0; i < n; ++i) {
            if (mp[node][i] != INF) {
                if (d + mp[node][i] < dis[i]) {
                    dis[i] = d + mp[node][i];
                    q.push({dis[i], i});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dis[i] << endl;
    }

    return 0;
}