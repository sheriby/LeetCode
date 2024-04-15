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

    int find(int x) {
        // parent[x] == x, 的结点是根节点，直接返回
        if (parent[x] != x) {
            // 路径压缩，每次查找的时候，直接将父节点设置为根
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 将x的根节点的父节点设置为y
    void unionSet(int x, int y) { parent[find(x)] = find(y); }

    // 返回两个元素是否在同一个集合
    bool isSameSet(int x, int y) { return find(x) == find(y); }

    int setCount() {
        int res = 0;
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == i) res++;
        }
        return res;
    }
};

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (i != j && isConnected[i][j] == 1) {
                    uf.unionSet(i, j);
                }
            }
        }
        return uf.setCount();
    }
};