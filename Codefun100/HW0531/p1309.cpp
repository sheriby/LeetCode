#include <bits/stdc++.h>
using namespace std;

inline string repeat(int times, int a) { return string(times, a + '0'); }
typedef pair<int, int> PII;

int main() {
    int m, n;
    cin >> m >> n;
    string res = "";
    priority_queue<PII> data;
    queue<PII> q;
    int len, num;
    for (int i = 0; i < n; ++i) {
        cin >> len >> num;
        data.push({num, len});
        int tmp = m;
        while (data.size() && tmp > 0) {
            num = data.top().first, len = data.top().second;
            if (len >= tmp) {
                cout << repeat(tmp, num) << endl;
                break;
            } else {
                cout << repeat(len, num);
                tmp -= len;
            }
            q.push({num, len});
            data.pop();
        }
        while (q.size()) {
            data.push(q.front());
            q.pop();
        }
    }
    return 0;
}