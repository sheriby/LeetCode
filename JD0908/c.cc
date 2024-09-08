#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int t = 0; t < N; t++) {
        int n, k, sum;
        cin >> n >> k >> sum;
        int cnt = 0;
        priority_queue<int> pq;
        for (int i = 1; i <= n; i++) {
            pq.push(i);
        }
        while (true) {
            int cnt = 0;
            vector<int> ans;
            int s = 0;
            for (int i = 0; i < k; i++) {
                int top = pq.top();
                pq.pop();
                ans.push_back(top);
                s += top;
            }
            if (s <= sum) {
                cout << cnt << endl;
                break;
            }
            ans[0]--; 
            for (int i = 0; i < k; i++) 
                pq.push(ans[i]);
        }
    }
    return 0;
}