#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }
    void _union(int x, int y) { parent[find(x)] = find(y); }
    bool isSameSet(int x, int y) { return find(x) == find(y); }
};

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for (auto edge : edges) {
            if (uf.isSameSet(edge[0], edge[1])) {
                return edge;
            } else {
                uf._union(edge[0], edge[1]);
            }
        }
    }
};
