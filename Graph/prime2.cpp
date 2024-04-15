#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

#define N 1003
#define M 10003
#define INF 0x3f3f3f3f

typedef pair<int, int> PII;

int n;  // n表示点数
int h[N], e[M], ne[M], w[M], idx;
int dist[N];  // 存储其他点到当前最小生成树的距离
int vis[N];   // 存储每个点是否已经在生成树中

// 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
int prim() {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII> q;
    q.push({0, 1});
    int res = 0;
    int cnt = 0;

    while (!q.empty()) {
        int t = q.top().second;
        if (vis[t]) continue;
        vis[t] = 1;
        res -= q.top().first;
        cnt++;
        q.pop();
        for (int i = h[t]; i; i = ne[i]) {
            int j = e[i];
            if (!vis[j] && dist[j] > w[i]) {
                dist[j] = w[i];
                q.push({-dist[j], j});
            }
        }
    }

    if (cnt != n) return INF;
    return res;
}