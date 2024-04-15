#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define N 1003
#define M 10003
#define INF 0x3f3f3f3f

typedef pair<int, int> PII;

int n;                             // 点的数量
int h[N], w[M], e[M], ne[M], idx;  // 邻接表存储所有边
int dist[N];                       // 存储所有点到1号点的距离
bool st[N];  // 存储每个点的最短距离是否已确定

// 求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});  // first存储距离，second存储节点编号

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == INF) return -1;
    return dist[n];
}