#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define N 1003
#define M 10003

int n, m;  // n是点数，m是边数
int p[N];  // 并查集的父节点数组

// 存储边
struct Edge {
    int a, b, w;
    bool operator<(const Edge &W) const { return w < W.w; }
} edges[M];

// 并查集核心操作
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    // 初始化排序，从小到大选边
    sort(edges, edges + m);

    for (int i = 1; i <= n; i++) p[i] = i;  // 初始化并查集

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        // 如果两个连通块不连通，则将这两个连通块合并
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    if (cnt < n - 1) return -1;
    return res;
}