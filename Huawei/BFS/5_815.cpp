#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
class Solution {
   public:
    // 经典的车站换乘问题，核心是将每一条公交路线当作一个节点来建图
    // 然后利用BFS一层一层的遍历
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        int len = routes.size();
        // 通过站点得到经过该站点的所有的公交路线
        unordered_map<int, vector<int>> station2route;
        for (int i = 0; i < len; ++i) {
            for (int station : routes[i]) station2route[station].push_back(i);
        }

        // 存放当前的站点和转乘的次数
        queue<PII> q;
        q.push({source, 0});
        vector<bool> vis_route(len + 1, false);
        vector<bool> vis_station(100001, false);

        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int station = q.front().first, trans = q.front().second;
                vis_station[source] = true;
                q.pop();
                if (station == target) return trans;
                // 看该站点的所有的公交路线
                for (int route : station2route[station]) {
                    if (vis_route[route]) continue;
                    vis_route[route] = true;
                    // 该公交路线的所有的站点
                    for (int j = 0; j < routes[route].size(); ++j) {
                        if (vis_station[routes[route][j]]) continue;
                        q.push({routes[route][j], trans + 1});
                    }
                }
            }
        }
        return -1;
    }
};