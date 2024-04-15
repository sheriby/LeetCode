#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
int main() {
    int n, k;
    cin >> n >> k;
    vector<PII> support(n);
    priority_queue<PII, vector<PII>, greater<PII>> q;  // 小顶堆
    int x, y, sup;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        sup = x + 2 * y;
        if (q.size() < k)
            q.push({sup, i});
        else if (sup > q.top().first) {
            q.pop();
            q.push({sup, i});
        }
    }
    vector<int> res;
    while (q.size()) {
        res.push_back(q.top().second);
        q.pop();
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}